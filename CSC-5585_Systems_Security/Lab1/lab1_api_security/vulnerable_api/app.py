import os, time, sqlite3, secrets, jwt
from functools import wraps
from flask import Flask, request, jsonify, g, send_from_directory
from flask_cors import CORS
from werkzeug.security import generate_password_hash, check_password_hash

# ============================================================== APPLICATION
app = Flask(__name__)

# Dynamically set the database path relative to the location of app.py
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DB = os.path.join(BASE_DIR, "vulnmart.db")

# TODO (1) - JWT Secret Management
# This is a weak, hardcoded, guessable secret - anyone reading this file
# could forge valid tokens with it.
#
# >>> Replace the line below with:
#         JWT_SECRET = os.environ.get("VULNMART_JWT_SECRET", secrets.token_hex(32))
JWT_SECRET = "vulnmart-secret-123"
JWT_ALGO = "HS256"
JWT_EXPIRATION_SECONDS = 3 * 60  # token lifetime to use once TODO (3) is fixed

# ====================================================================== CORS
# TODO (2) - Restrictive CORS
# "*" + credentials lets ANY website make authenticated requests on a
# victim's behalf.
#
# >>> Replace "origins": "*" below with an explicit allowlist, e.g.:
#         "origins": ["http://127.0.0.1:5001", "http://localhost:5001"]
#     and remove supports_credentials=True (it isn't needed with a Bearer token).
CORS(app, resources={r"/api/*": {"origins": "*"}}, supports_credentials=True)

# ========================================================= RATE LIMITING
# Simple in-memory limiter, intentionally basic for a teaching app.
# The tracking logic below is already implemented for you - TODO (4) only
# asks you to CALL it at the two spots marked further down (login, register).
RATE_LIMIT_WINDOW_SECONDS = 60
RATE_LIMIT_MAX_ATTEMPTS = 5
rate_limit_attempts = {}  # keyed by (bucket, ip) so buckets don't share/reset each other's counts

def rate_limit_exceeded(bucket, ip):
    now = time.time()
    key = (bucket, ip)
    attempts = [t for t in rate_limit_attempts.get(key, []) if now - t < RATE_LIMIT_WINDOW_SECONDS]
    rate_limit_attempts[key] = attempts
    return len(attempts) >= RATE_LIMIT_MAX_ATTEMPTS

def record_rate_limited_attempt(bucket, ip):
    now = time.time()
    key = (bucket, ip)
    attempts = [t for t in rate_limit_attempts.get(key, []) if now - t < RATE_LIMIT_WINDOW_SECONDS]
    attempts.append(now)
    rate_limit_attempts[key] = attempts

# ================================================================= FRONTEND
@app.route("/")
def index(): return send_from_directory(".", "index.html")

@app.route("/profile.html")
def profile_page(): return send_from_directory(".", "profile.html")

@app.route("/orders.html")
def orders_page(): return send_from_directory(".", "orders.html")

@app.route("/products.html")
def products_page(): return send_from_directory(".", "products.html")

# ================================================================== DATABASE
def get_db():
    if "db" not in g:
        g.db = sqlite3.connect(DB)
        g.db.row_factory = sqlite3.Row
    return g.db

@app.teardown_appcontext
def close_db(exception=None):
    db = g.pop("db", None)
    if db is not None: db.close()

def init_db():
    conn = sqlite3.connect(DB)
    c = conn.cursor()
    c.executescript("""
        DROP TABLE IF EXISTS orders;
        DROP TABLE IF EXISTS users;
        CREATE TABLE users (
            id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT UNIQUE NOT NULL,
            password_hash TEXT NOT NULL, email TEXT NOT NULL, ssn TEXT,
            balance REAL DEFAULT 0, is_admin INTEGER DEFAULT 0
        );
        CREATE TABLE orders (
            id INTEGER PRIMARY KEY AUTOINCREMENT, user_id INTEGER NOT NULL,
            item TEXT NOT NULL, amount REAL NOT NULL, status TEXT DEFAULT 'placed',
            FOREIGN KEY (user_id) REFERENCES users(id)
        );
    """)

    users = [
        ("alice", "alicepw", "alice@example.com", "111-22-3333", 250.00, 0),
        ("bob",   "bobpw",   "bob@example.com",   "222-33-4444", 40.00,  0),
        ("admin", "adminpw", "admin@vulnmart.local", "000-00-0000", 0.00, 1),
    ]
    for username, password, email, ssn, balance, is_admin in users:
        c.execute(
            "INSERT INTO users (username,password_hash,email,ssn,balance,is_admin) VALUES (?,?,?,?,?,?)",
            (username, generate_password_hash(password), email, ssn, balance, is_admin)
        )

    orders = [
        (1, "Wireless Mouse", 19.99), (1, "Mechanical Keyboard", 89.00),
        (2, "USB-C Cable", 9.50), (3, "Server Rack (internal)", 1200.00),
    ]
    for user_id, item, amount in orders:
        c.execute("INSERT INTO orders (user_id,item,amount) VALUES (?,?,?)", (user_id, item, amount))

    conn.commit()
    conn.close()

# ======================================================================= JWT
def make_token(user_row):
    now = int(time.time())
    payload = {
        "user_id": user_row["id"],
        "username": user_row["username"],
        "is_admin": bool(user_row["is_admin"]),
        # TODO (3) - JWT Expiration
        # This token never expires. Add two claims here so it does:
        #     "iat": now,
        #     "exp": now + JWT_EXPIRATION_SECONDS,
    }
    return jwt.encode(payload, JWT_SECRET, algorithm=JWT_ALGO)

# ============================================================ AUTHENTICATION
def get_current_user():
    # Note: this already correctly rejects an expired token via
    # jwt.ExpiredSignatureError - nothing to change here. It will start
    # working the moment you add "exp" to the payload above (TODO 3).
    auth_header = request.headers.get("Authorization", "")
    if not auth_header.startswith("Bearer "): return None
    token = auth_header[len("Bearer "):]
    try:
        return jwt.decode(token, JWT_SECRET, algorithms=[JWT_ALGO])
    except (jwt.ExpiredSignatureError, jwt.InvalidTokenError):
        return None

def require_auth(function):
    @wraps(function)
    def wrapper(*args, **kwargs):
        user = get_current_user()
        if not user: return jsonify({"error": "unauthorized"}), 401
        g.current_user = user
        return function(*args, **kwargs)
    return wrapper

def require_admin(function):
    @wraps(function)
    def wrapper(*args, **kwargs):
        user = get_current_user()
        if not user: return jsonify({"error": "unauthorized"}), 401
        if not user.get("is_admin", False): return jsonify({"error": "forbidden"}), 403
        g.current_user = user
        return function(*args, **kwargs)
    return wrapper

def require_same_user(user_id):
    # Already implemented for you - just call this where the comments below
    # tell you to (TODOs 6, 7, 8).
    authenticated_user_id = int(g.current_user["user_id"])
    if authenticated_user_id != user_id:
        return jsonify({"error": "forbidden"}), 403
    return None

# ===================================================================== LOGIN
@app.route("/api/login", methods=["POST"])
def login():
    ip = request.remote_addr or "unknown"
    # TODO (4) - Rate Limiting
    # Call the two functions defined above (rate_limit_exceeded /
    # record_rate_limited_attempt) with bucket="login" and this ip. See the
    # secure /api/register version further down once you've done this once -
    # both endpoints need the same three lines.

    data = request.get_json(silent=True)
    if not isinstance(data, dict):
        return jsonify({"error": "invalid JSON body"}), 400

    username, password = data.get("username"), data.get("password")
    if not isinstance(username, str) or not isinstance(password, str) or not username or not password:
        return jsonify({"error": "username and password are required"}), 400

    db = get_db()
    row = db.execute("SELECT * FROM users WHERE username = ?", (username,)).fetchone()
    if not row or not check_password_hash(row["password_hash"], password):
        return jsonify({"error": "invalid credentials"}), 401

    return jsonify({"token": make_token(row)})

# ============================================================= USER PROFILE
@app.route("/api/users/<int:user_id>", methods=["GET"])
@require_auth
def get_user(user_id):
    # TODO (6) - Profile BOLA / Excessive Data Exposure
    # Two things are wrong here:
    #   (a) there's no ownership check, so any logged-in user can view any
    #       other user's profile by changing the id in the URL.
    #   (b) the query below returns EVERY column, including ssn/balance/
    #       password_hash.
    #
    # >>> Add before the "db = get_db()" line:
    #         authorization_error = require_same_user(user_id)
    #         if authorization_error: return authorization_error
    #
    # >>> Then change the SELECT below to only: id, username, email
    db = get_db()
    row = db.execute("SELECT * FROM users WHERE id = ?", (user_id,)).fetchone()
    if not row: return jsonify({"error": "not found"}), 404
    return jsonify(dict(row))

# ============================================================== USER ORDERS
@app.route("/api/users/<int:user_id>/orders", methods=["GET"])
@require_auth
def user_orders(user_id):
    # TODO (8) - Orders BOLA
    # Any logged-in user can list any other user's orders by changing the id
    # in the URL - there's no ownership check.
    #
    # >>> Add before "db = get_db()":
    #         authorization_error = require_same_user(user_id)
    #         if authorization_error: return authorization_error
    db = get_db()
    rows = db.execute(
        "SELECT id, user_id, item, amount, status FROM orders WHERE user_id = ?", (user_id,)
    ).fetchall()
    return jsonify([dict(row) for row in rows])

# =============================================================== SINGLE ORDER
@app.route("/api/orders/<int:order_id>", methods=["GET"])
@require_auth
def get_order(order_id):
    current_user_id = int(g.current_user["user_id"])
    db = get_db()
    # TODO (9) - Single-Order Authorization
    # This query fetches an order by id alone - it never checks that the
    # order belongs to current_user_id, so any user can read any order.
    #
    # >>> Change the query to also filter by owner, e.g.:
    #         "SELECT id, user_id, item, amount, status FROM orders WHERE id = ? AND user_id = ?"
    #     and pass (order_id, current_user_id) as the parameters.
    row = db.execute(
        "SELECT id, user_id, item, amount, status FROM orders WHERE id = ?", (order_id,)
    ).fetchone()
    if not row: return jsonify({"error": "not found"}), 404
    return jsonify(dict(row))

# =================================================================== ADMIN
# TODO (10) - Function-Level Authorization
# @require_auth only checks that the caller is logged in, not that they're
# an admin - so Alice can call this too.
#
# >>> Change the decorator on the line below from @require_auth to @require_admin
@app.route("/api/admin/users", methods=["GET"])
@require_auth
def admin_list_users():
    db = get_db()
    rows = db.execute("SELECT id, username, email, is_admin FROM users").fetchall()
    return jsonify([dict(row) for row in rows])

# ================================================================= REGISTER
@app.route("/api/register", methods=["POST"])
def register():
    ip = request.remote_addr or "unknown"
    # TODO (4) - Rate Limiting (same fix as /api/login above)

    data = request.get_json(silent=True)
    if not isinstance(data, dict):
        return jsonify({"error": "invalid JSON body"}), 400

    username = data.get("username")
    password = data.get("password")
    email = data.get("email")

    if not isinstance(username, str) or not isinstance(password, str) or not isinstance(email, str):
        return jsonify({"error": "username, password, and email are required"}), 400
    username, email = username.strip(), email.strip()
    if not username: return jsonify({"error": "username cannot be empty"}), 400
    if len(username) > 50: return jsonify({"error": "username too long"}), 400
    if len(password) < 8: return jsonify({"error": "password must be at least 8 characters"}), 400
    if len(email) > 254: return jsonify({"error": "email too long"}), 400

    # TODO (5) - Registration Mass Assignment
    # A client can currently register with balance=999999 and is_admin=1
    # because those values are taken straight from the request body.
    #
    # >>> Replace the two lines below with fixed, server-side values:
    #         balance = 0.0
    #         is_admin = 0
    balance = data.get("balance", 0.0)
    is_admin = data.get("is_admin", 0)

    db = get_db()
    try:
        db.execute(
            "INSERT INTO users (username,password_hash,email,ssn,balance,is_admin) VALUES (?,?,?,?,?,?)",
            (username, generate_password_hash(password), email, None, balance, is_admin)
        )
        db.commit()
    except sqlite3.IntegrityError:
        return jsonify({"error": "username already exists"}), 409

    return jsonify({"message": "registered"}), 201

# =============================================================== UPDATE USER
@app.route("/api/users/<int:user_id>", methods=["PUT"])
@require_auth
def update_user(user_id):
    # TODO (7) - Update Authorization / Property Control
    # Two things are wrong here:
    #   (a) there's no ownership check, so any user can edit any user_id.
    #   (b) allowed_fields below lets the client overwrite balance/is_admin/ssn.
    #
    # >>> Add before "data = request.get_json(...)":
    #         authorization_error = require_same_user(user_id)
    #         if authorization_error: return authorization_error
    #
    # >>> Then change allowed_fields to only: ["email"]
    data = request.get_json(silent=True)
    if not isinstance(data, dict):
        return jsonify({"error": "invalid JSON body"}), 400

    allowed_fields = ["email", "balance", "is_admin", "ssn"]
    unexpected_fields = set(data.keys()) - set(allowed_fields)
    if unexpected_fields:
        return jsonify({"error": "one or more fields are not editable"}), 400

    db = get_db()
    fields, values = [], []
    for key in allowed_fields:
        if key in data:
            fields.append(f"{key} = ?")
            values.append(data[key])
    if not fields:
        return jsonify({"error": "no editable fields supplied"}), 400

    values.append(user_id)
    db.execute(f"UPDATE users SET {', '.join(fields)} WHERE id = ?", values)
    db.commit()
    return jsonify({"message": "updated"})

# ====================================================================== SEARCH
@app.route("/api/products", methods=["GET"])
@require_auth
def search_products():
    search = request.args.get("search", "").strip()
    if len(search) > 50:
        return jsonify({"error": "search query too long"}), 400

    db = get_db()
    # TODO (11) - SQL Injection Prevention
    # User input is concatenated straight into the SQL text below, so a
    # crafted "search" value can change the query's meaning.
    #
    # >>> Replace the query line with a parameterized version:
    #         rows = db.execute(
    #             "SELECT id, username, email FROM users WHERE username LIKE ?", (f"%{search}%",)
    #         ).fetchall()
    query = f"SELECT id, username, email FROM users WHERE username LIKE '%{search}%'"
    rows = db.execute(query).fetchall()
    return jsonify([dict(row) for row in rows])

# ====================================================================== HEALTH
@app.route("/api/health", methods=["GET"])
def health():
    # TODO (12) Bonus - API Versioning
    # >>> Add a "version": "v1" key to the response below.
    return jsonify({"status": "ok"})

# ================================================================= START APP
if __name__ == "__main__":
    init_db()

    print(
        "\n" + "=" * 60
        + "\nVULNMART - API SECURITY LAB (VULNERABLE / STUDENT VERSION)\n"
        + "=" * 60
    )

    print("\nOpen:\n  http://127.0.0.1:5000/\n")

    print(
        "Demo accounts:\n"
        "  alice / alicepw\n"
        "  bob   / bobpw\n"
        "  admin / adminpw\n"
    )

    print(
        "API:\n"
        "  /api/login\n"
        "  /api/register\n"
        "  /api/users/<id>\n"
        "  /api/users/<id>/orders\n"
        "  /api/orders/<id>\n"
        "  /api/admin/users\n"
        "  /api/products\n"
        "  /api/health\n"
    )

    print("Student tasks:")
    print("  TODO (1)  Secure JWT secret")
    print("  TODO (2)  Restrictive CORS")
    print("  TODO (3)  JWT expiration")
    print("  TODO (4)  Rate limiting")
    print("  TODO (5)  Registration mass assignment")
    print("  TODO (6)  Profile BOLA / data exposure")
    print("  TODO (7)  Update authorization / property controls")
    print("  TODO (8)  Orders BOLA")
    print("  TODO (9)  Single-order authorization")
    print("  TODO (10) Admin function authorization")
    print("  TODO (11) SQL injection prevention")
    print("  TODO (12) API versioning / inventory")
    print("=" * 60)

    app.run(host="127.0.0.1", port=5000, debug=False)