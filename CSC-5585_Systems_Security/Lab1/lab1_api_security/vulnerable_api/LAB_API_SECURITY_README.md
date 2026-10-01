# Lab 1 — API Security Lab Instruction

## Overview

This lab will use two locally running versions of the VulnMart application:

| Application | URL | Purpose |
|---|---|---|
| Vulnerable application | `http://127.0.0.1:5000` | Demonstrate the insecure behavior before a security control is implemented. |
| Secure application | `http://127.0.0.1:5001` | Verify that the corresponding security control rejects or prevents the insecure behavior. |


The vulnerable code base is given to you first. **Complete and test the vulnerable application before building or testing the secure application.** Use the vulnerable application to observe and document the insecure behavior for each checkpoint. After you have completed the vulnerable-side tests, copy the vulnerable code base for the secure application, run it on a different port (`5001`), and implement the required security controls only inside the `app.py` file in the given `TO-DO` sections. Then repeat the same checkpoints against the secure application and compare the results. Keep both code bases at the same directory level and use distinct SQLite databases with the same name in both folders (this should happen automatically if you do not manually change anything). Running the applications side by side is optional; if both localhost servers cause a conflict, run and test them one at a time.

<strong style="color: red;">Keep running the <code>app.py</code> all the time. This is your backend server code.</strong>


## Deliverables:

- Completed Table
- Answer to the questions

> **Important:** Run these tests only against the VulnMart lab applications supplied for this course and only on your local machine.

---

# Required Submission

For each checkpoint:

1. **Run and record the test against the vulnerable application first.**
2. Implement the corresponding security control in your secure application.
3. Run the same test against your developed secure application.
3. Complete the final comparison table (<strong>With captured screenshots</strong>).
4. Answer the questions and report it along with the completed table.

Some controls are configuration/design controls rather than a single request-response vulnerability. For those checkpoints, inspect the relevant behavior and document the evidence requested.

---

# Common Cross-Platform Setup

The following commands make it easier to run authenticated tests. Ubuntu examples use `curl`; Windows examples use PowerShell cmdlets or `curl.exe`.

## Login as Alice

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/login" `
  -Method POST `
  -Body (@{username="alice"; password="alicepw"} | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5000/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
```

For the secure application, change port `5000` to `5001`.

## Reusable Authorization Header

```powershell
$headers = @{
    Authorization = "Bearer $token"
}
```

### Ubuntu / Bash

```bash
headers=(-H "Authorization: Bearer $token")
```

---

# TODO (1) — JWT Secret Management

## Security objective

The JWT signing secret must not be a predictable, weak, hardcoded value.

## Checkpoint

This control is primarily verified by implementation/configuration inspection.

Students should verify that the secure implementation:

- does not use the vulnerable hardcoded value;
- loads the secret from secure configuration, such as an environment variable;
- For this lab application, provide a cryptographically secure fallback so the application can still run locally when the environment variable is not configured..

## PowerShell configuration check

For the secure application, set a known lab secret before starting the application:

```powershell
$env:VULNMART_JWT_SECRET = "lab-demo-secret-change-this-in-production"
```

### Ubuntu / Bash

```bash
export VULNMART_JWT_SECRET="lab-demo-secret-change-this-in-production"
```

Then restart the application without setting the environment variable and verify that the application still runs.

## Expected comparison

| Version | Expected result |
|---|---|
| Vulnerable | Predictable hardcoded signing secret is present in the implementation. |
| Secure | Secret is obtained from configuration or generated securely; the vulnerable hardcoded secret is not used. |

## Student checkpoint

Record:

- how the vulnerable secret is defined;
- how the secure secret is obtained;
- whether the application still starts when the environment variable is absent.

---

# TODO (2) — Restrictive CORS

## Security objective

The API must not allow arbitrary web origins to make cross-origin requests with inappropriate access.

## API check

Inspect the response headers for a request containing an untrusted `Origin`.

```powershell
curl.exe -i `
  -H "Origin: http://evil.example" `
  "http://127.0.0.1:5000/api/health"
```

### Ubuntu / Bash

```bash
curl -i -H "Origin: http://evil.example" "http://127.0.0.1:5000/api/health"
```

Run the equivalent secure test on secure website:

```powershell
curl.exe -i `
  -H "Origin: http://evil.example" `
  "http://127.0.0.1:5001/api/health"
```

### Ubuntu / Bash

```bash
curl -i -H "Origin: http://evil.example" "http://127.0.0.1:5001/api/health"
```

Then test an allowed origin for the secure application, based on the configured CORS allowlist:

```powershell
curl.exe -i `
  -H "Origin: http://127.0.0.1:5001" `
  "http://127.0.0.1:5001/api/health"
```

### Ubuntu / Bash

```bash
curl -i -H "Origin: http://127.0.0.1:5001" "http://127.0.0.1:5001/api/health"
```

## What to record

Look for headers such as:

```text
Access-Control-Allow-Origin
Access-Control-Allow-Credentials
```

## Expected comparison

| Version | Untrusted origin |
|---|---|
| Vulnerable | CORS policy is overly permissive. |
| Secure | Untrusted origin should not receive permission through the configured allowlist. |

---

# TODO (3) — JWT Expiration

## Security objective

Authentication tokens should have a limited lifetime.

## Step 1: Obtain a token

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/login" `
  -Method POST `
  -Body (@{username="alice"; password="alicepw"} | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5000/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
```

## Step 2: Verify the token works immediately

```powershell
Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/users/1" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/users/1" "${headers[@]}"
```

## Step 3: Wait for expiration

The secure application defines a token lifetime. Wait until the configured lifetime has passed, then run the same request again.

```powershell
Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/users/1" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/users/1" "${headers[@]}"
```

For the vulnerable application, repeat the same experiment using port `5000`.

## Expected comparison

| Version | After configured token lifetime |
|---|---|
| Vulnerable | Token has no expiration claim and remains usable while otherwise valid. |
| Secure | Expired token is rejected and the request returns an unauthorized response. |

## Student checkpoint

Record the status before expiration and after expiration.

---

# TODO (4) — Rate Limiting

## Security objective

Repeated requests, especially authentication attempts, must be throttled.

## PowerShell test

Run the given `rate_limit_chk.py` and capture the `RATE LIMIT TEST RESULTS`.

```powershell
python3 rate_limit_chk.py
```

Repeat against the secure application using port `5001`.

## Ubuntu / Bash test

```bash
python3 rate_limit_chk.py
```

Repeat against the secure application using port `5001`. If the script has a configurable target URL/port, set it to `http://127.0.0.1:5001` before rerunning. Do not assume a command-line port option unless it is implemented by the supplied script.

## Expected comparison

| Version | Repeated attempts |
|---|---|
| Vulnerable | Requests continue without a throttling response. |
| Secure | After the configured threshold, requests receive `429 Too Many Requests`. |

## Student checkpoint

Observe:

- the configured maximum attempts;
- the first request number that receives `429`;
- whether the vulnerable application ever returns `429`.

---

# TODO (5) — Registration Mass Assignment and Input Validation

## Security objective

A client registering a new account must not be able to set protected properties such as account balance or administrator status.

## Normal registration request

```powershell
$body = @{
    username = "mallory"
    password = "mallorypw"
    email    = "mallory@example.com"
    balance  = 0
    is_admin = 0
} | ConvertTo-Json

Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/register" `
  -Method POST `
  -Body $body `
  -ContentType "application/json"
```

### Ubuntu / Bash

```bash
curl -i -X POST "http://127.0.0.1:5000/api/register" -H "Content-Type: application/json" -d '{"username":"mallory","password":"mallorypw","email":"mallory@example.com","balance":0,"is_admin":0}'
```

Repeat using port `5001`.

## Malicious mass-assignment request

```powershell
$body = @{
    username = "mallory1"
    password = "mallory1pw"
    email    = "mallory1@example.com"
    balance  = 999999
    is_admin = 1
} | ConvertTo-Json

Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/register" `
  -Method POST `
  -Body $body `
  -ContentType "application/json"
```

### Ubuntu / Bash

```bash
curl -i -X POST "http://127.0.0.1:5000/api/register" -H "Content-Type: application/json" -d '{"username":"mallory1","password":"mallory1pw","email":"mallory1@example.com","balance":999999,"is_admin":1}'
```

Repeat using port `5001`.

## Verify the resulting account

Log in as the newly created account and inspect the account through the appropriate API behavior available in the lab.
The admin status and default balance should be 0 even if you try to assign it manually.



## Expected comparison

| Version | Malicious `balance` / `is_admin` |
|---|---|
| Vulnerable | Protected properties can be controlled by the client. |
| Secure | Protected properties are ignored or rejected; server assigns safe defaults. |

## Input validation checkpoint

Also test malformed registration input, for example:

```powershell
$body = @{
    username = ""
    password = "short"
    email    = ""
} | ConvertTo-Json

Invoke-WebRequest `
  -Uri "http://127.0.0.1:5000/api/register" `
  -Method POST `
  -Body $body `
  -ContentType "application/json"
```

### Ubuntu / Bash

```bash
curl -i -X POST "http://127.0.0.1:5000/api/register" -H "Content-Type: application/json" -d '{"username":"","password":"short","email":""}'
```

Record the secure application's validation response. 

---

# TODO (6) — Profile BOLA / IDOR and Excessive Data Exposure

## Security objective

Authentication alone is not sufficient. A user must not access another user's profile without authorization, and sensitive fields should not be unnecessarily returned.

## Login as Alice

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/login" `
  -Method POST `
  -Body (@{username="alice"; password="alicepw"} | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5000/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
```

## Alice requests her own profile

```powershell
Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/users/1" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/users/1" "${headers[@]}"
```

## Alice requests Bob's profile

```powershell
Invoke-WebRequest `
  -Uri "http://127.0.0.1:5000/api/users/2" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/users/2" "${headers[@]}"
```

Repeat both tests on port `5001`.

## What to compare

For the vulnerable application, inspect whether the response exposes sensitive fields such as:

- `ssn`
- `balance`
- `password_hash`
- `is_admin`

## Expected comparison

| Version | Alice requests `/api/users/2` |
|---|---|
| Vulnerable | Another user's record can be accessed and excessive fields may be exposed. |
| Secure | Request is denied by object-level authorization. |

---

# TODO (7) — Update User: Ownership and Property-Level Authorization

## Security objective

A user must not update another user's account or modify protected properties.

## Test A: Alice attempts to modify her own protected properties

First log in as Alice:

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/login" `
  -Method POST `
  -Body (@{username="alice"; password="alicepw"} | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5000/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
```

Attempt to change sensitive properties:

```powershell
$body = @{
    balance  = 999999
    is_admin = 1
} | ConvertTo-Json

Invoke-WebRequest `
  -Uri "http://127.0.0.1:5000/api/users/1" `
  -Method PUT `
  -Headers $headers `
  -Body $body `
  -ContentType "application/json"
```

### Ubuntu / Bash

```bash
curl -i -X PUT "http://127.0.0.1:5000/api/users/1" "${headers[@]}" -d '{"balance":999999,"is_admin":1}'
```

Repeat against port `5001`.

## Test B: Alice attempts to modify Bob's account

```powershell
$body = @{
    email = "attacker-change@example.com"
} | ConvertTo-Json

Invoke-WebRequest `
  -Uri "http://127.0.0.1:5000/api/users/2" `
  -Method PUT `
  -Headers $headers `
  -Body $body `
  -ContentType "application/json"
```

### Ubuntu / Bash

```bash
curl -i -X PUT "http://127.0.0.1:5000/api/users/2" "${headers[@]}" -d '{"email":"attacker-change@example.com"}'
```

Repeat against port `5001`.

## Vulnerable application behavior

The vulnerable `app.py` is intentionally missing the ownership and property-level checks. Therefore, the vulnerable tests should reach the update logic and return `200` rather than being blocked by authorization. The important detail is that the request must be sent as JSON (`Content-Type: application/json`); otherwise Flask's `request.get_json()` will reject the body before the vulnerable behavior is reached.

## Expected comparison

| Test | Vulnerable | Secure |
|---|---|---|
| Modify own protected fields | Accepted | Protected fields rejected/not editable |
| Modify another user's account | Accepted | Forbidden |

---

# TODO (8) — BOLA: Access Another User's Orders

## Security objective

An authenticated user must only access order collections that belong to that user.

## Login as Alice

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/login" `
  -Method POST `
  -Body (@{username="alice"; password="alicepw"} | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5000/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
```

## Request Alice's orders

```powershell
Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/users/1" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/users/1" "${headers[@]}"
```

## Request Bob's orders

```powershell
Invoke-WebRequest `
  -Uri "http://127.0.0.1:5000/api/users/2" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/users/2" "${headers[@]}"
```

Repeat against port `5001`.

## Expected comparison

| Version | Alice requests Bob's orders |
|---|---|
| Vulnerable | Bob's orders are returned. |
| Secure | Request is rejected by object-level authorization. |

---

# TODO (9) — BOLA: Access Another User's Individual Order

## Security objective

An authenticated user must not retrieve an order simply by guessing or changing an order identifier.

The initial database contains:

- Alice orders: IDs `1` and `2`
- Bob order: ID `3`
- Admin order: ID `4`

## Login as Alice

Use the same Alice login procedure from the previous checkpoint.

## Request Alice's order

```powershell
Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/orders/1" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/orders/1" "${headers[@]}"
```

## Request Bob's order

```powershell
Invoke-WebRequest `
  -Uri "http://127.0.0.1:5000/api/orders/3" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/orders/3" "${headers[@]}"
```

Repeat against port `5001`.

## Expected comparison

| Version | Alice requests order `3` |
|---|---|
| Vulnerable | Bob's order can be retrieved. |
| Secure | Order is not returned to Alice. |

---

# TODO (10) — Missing Function-Level Authorization

## Security objective

An endpoint intended for administrators must verify administrator privileges, not merely authentication.

## Vulnerable test: normal user calls admin endpoint

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/login" `
  -Method POST `
  -Body (@{
      username = "alice"
      password = "alicepw"
  } | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token

Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/admin/users" `
  -Method GET `
  -Headers @{Authorization = "Bearer $token"}
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5000/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
curl -i "http://127.0.0.1:5000/api/admin/users" -H "Authorization: Bearer $token"
```

## Secure test: normal user calls admin endpoint

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5001/api/login" `
  -Method POST `
  -Body (@{
      username = "alice"
      password = "alicepw"
  } | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token

Invoke-RestMethod `
  -Uri "http://127.0.0.1:5001/api/admin/users" `
  -Method GET `
  -Headers @{Authorization = "Bearer $token"}
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5001/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
curl -i "http://127.0.0.1:5001/api/admin/users" -H "Authorization: Bearer $token"
```

## Optional administrator verification

Log in as `admin` and verify that the secure administrator account can access the endpoint.

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5001/api/login" `
  -Method POST `
  -Body (@{
      username = "admin"
      password = "adminpw"
  } | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token

Invoke-RestMethod `
  -Uri "http://127.0.0.1:5001/api/admin/users" `
  -Method GET `
  -Headers @{Authorization = "Bearer $token"}
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5001/api/login" -H "Content-Type: application/json" -d '{"username":"admin","password":"adminpw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
curl -i "http://127.0.0.1:5001/api/admin/users" -H "Authorization: Bearer $token"
```

## Expected comparison

| Version | Alice accesses `/api/admin/users` |
|---|---|
| Vulnerable | Request succeeds because authentication is treated as sufficient. |
| Secure | Request is rejected with `403 Forbidden`. |

---

# TODO (11) Bonus — SQL Injection Products API/Page

## Security objective

Untrusted input must not be concatenated into SQL statements. API data must also be rendered safely by the frontend so database-controlled text is not interpreted as executable HTML.

## Authentication required

The `/api/products` endpoint requires authentication. Before running the SQL injection or XSS tests, log in as Alice and create the authorization header.

### PowerShell

```powershell
$login = Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/login" `
  -Method POST `
  -Body (@{username="alice"; password="alicepw"} | ConvertTo-Json) `
  -ContentType "application/json"

$token = $login.token
$headers = @{ Authorization = "Bearer $token" }
```

### Ubuntu / Bash

```bash
token=$(curl -s -X POST "http://127.0.0.1:5000/api/login" -H "Content-Type: application/json" -d '{"username":"alice","password":"alicepw"}' | python3 -c 'import json,sys; print(json.load(sys.stdin)["token"])')
headers=(-H "Authorization: Bearer $token")
```

For the secure application, repeat the login against port `5001` and use its token.

## SQL Injection

Use the products API with the following lab payload:

```text
' OR '1'='1
```

### Vulnerable application

```powershell
$payload = "' OR '1'='1"
$encoded = [uri]::EscapeDataString($payload)

Invoke-WebRequest `
  -Uri "http://127.0.0.1:5000/api/products?search=$encoded" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
payload="' OR '1'='1"
curl -i -G "http://127.0.0.1:5000/api/products" "${headers[@]}" --data-urlencode "search=$payload"
```

### Secure application

```powershell
$payload = "' OR '1'='1"
$encoded = [uri]::EscapeDataString($payload)

Invoke-WebRequest `
  -Uri "http://127.0.0.1:5001/api/products?search=$encoded" `
  -Method GET `
  -Headers $headers
```

### Ubuntu / Bash

```bash
payload="' OR '1'='1"
curl -i -G "http://127.0.0.1:5001/api/products" "${headers[@]}" --data-urlencode "search=$payload"
```

## Vulnerable application behavior

The vulnerable endpoint is intentionally injectable. The test must include Alice's Bearer token because `/api/products` is protected by `@require_auth`. Without the token, the request stops at authentication and returns `401`, so the SQL injection is never reached.

With the authenticated request, the lab payload should alter the vulnerable SQL query and return rows that would not be returned by a normal search. The secure implementation should treat the same payload as data.

## Expected comparison

| Version | SQL injection payload |
|---|---|
| Vulnerable | Query behavior is altered by the injected SQL expression. |
| Secure | Input is treated as data; the query structure is not altered. |



Repeat against port `5001`.

## Browser test using `products.html`

1. Open the vulnerable `products.html` page.
2. Enter the supplied lab payload into the search field.
3. Submit the search.
4. Record whether returned content is interpreted as HTML/script-capable markup.
5. Repeat on the secure version.
6. Record whether the payload is displayed as inert text or otherwise safely handled.

## Expected comparison

| Version | Injected markup returned through API |
|---|---|
| Vulnerable | SQL injection can be used to influence returned data; unsafe frontend rendering may interpret attacker-controlled markup. |
| Secure | Parameterized SQL prevents the injected query from manufacturing attacker-controlled rows; safe frontend rendering must not execute returned markup. |

> **Student note:** This checkpoint has two layers. Fixing SQL injection prevents the crafted SQL from generating the malicious result, but frontend output handling must also avoid inserting untrusted strings using unsafe HTML APIs.

---

# TODO (12) Bonus — API Versioning and Inventory

## Security objective

The application should expose and document a clear API versioning strategy and maintain an inventory of active endpoints.

## Health endpoint check

Vulnerable application:

```powershell
Invoke-RestMethod `
  -Uri "http://127.0.0.1:5000/api/health" `
  -Method GET
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5000/api/health"
```

Secure application:

```powershell
Invoke-RestMethod `
  -Uri "http://127.0.0.1:5001/api/health" `
  -Method GET
```

### Ubuntu / Bash

```bash
curl -i "http://127.0.0.1:5001/api/health"
```

## Student implementation checkpoint

Document:

1. the API version exposed by the secure application;
2. where the version is represented;
3. the active API endpoints;
4. the HTTP methods accepted by each endpoint.

## Minimum API inventory table

| Endpoint | Method | Authentication | Authorization |
|---|---|---|---|
| `/api/login` | POST | No | Public |
| `/api/register` | POST | No | Public |
| `/api/users/<id>` | GET | Yes | Object owner policy |
| `/api/users/<id>` | PUT | Yes | Object owner + property policy |
| `/api/users/<id>/orders` | GET | Yes | Object owner policy |
| `/api/orders/<id>` | GET | Yes | Order owner policy |
| `/api/admin/users` | GET | Yes | Administrator only |
| `/api/products` | GET | Secure implementation policy | Search endpoint |
| `/api/health` | GET | No | Public |

> Update the inventory if your implementation changes endpoint paths to include a version prefix.

---

# Final Required Comparison Table

Complete this table using your observed results.

| TODO | Security Control | Vulnerable Result | Secure Result | Status Code(s) Observed |
|---|---|---|---|---|
| 1 | JWT secret management |  |  |  |
| 2 | Restrictive CORS |  |  |  |
| 3 | JWT expiration |  |  |  |
| 4 | Rate limiting |  |  |  |
| 5 | Registration mass assignment / validation |  |  |  |
| 6 | Profile BOLA / excessive data exposure |  |  |  |
| 7 | Update ownership / property authorization |  |  |  |
| 8 | Orders BOLA |  |  |  |
| 9 | Single-order BOLA |  |  |  |
| 10 | Function-level authorization |  |  |  |
| 11 | SQL injection / XSS handling |  |  |  |
| 12 | API versioning / inventory |  |  |  |

---

# Submission Questions

Answer the following questions after completing the tests.

1. Why is authentication different from authorization?
2. Which TODOs implement object-level authorization?
3. Which TODOs prevent client-controlled sensitive properties?
4. Why does parameterized SQL prevent the SQL injection checkpoint from changing query structure?
5. Why can preventing SQL injection alone be insufficient if a frontend renders untrusted API values using unsafe HTML insertion?
6. Why is returning a full database row dangerous even when access to the endpoint requires authentication?
7. Why is an authenticated user not automatically authorized to access an administrator endpoint?
8. What behavior changed after rate limiting was implemented?
9. What is the purpose of token expiration?
10. What information should be maintained in an API inventory?

---

# Instructor/Test Notes

The expected secure implementation behavior for this lab is:

- TODO (1): JWT secret is not a weak hardcoded constant.
- TODO (2): CORS uses an explicit origin allowlist.
- TODO (3): JWT contains an expiration and expired tokens are rejected.
- TODO (4): repeated authentication attempts eventually return `429`.
- TODO (5): registration cannot set `balance` or `is_admin`; invalid input is rejected.
- TODO (6): users cannot retrieve another user's profile; unnecessary sensitive fields are not returned.
- TODO (7): users cannot modify another user's account or protected properties.
- TODO (8): users cannot retrieve another user's order collection.
- TODO (9): users cannot retrieve another user's individual order.
- TODO (10): non-administrators receive `403` for administrator-only functionality.
- TODO (11): SQL input is parameterized and untrusted returned values are not executed as HTML.
- TODO (12): the API exposes a documented versioning/inventory strategy.

# Grading Criteria

- 0 for Blank Submission / Not able to run the vulnerable default application
- 25 for successful running of default vulnerable application
- 50 for at least 1 correct TODO implementations
- 60 for at least 2 correct TODO implementations
- 70 for at least 4 TODO implementations
- 80 for at least 6 TODO implementations
- 90 for at least 8 correct TODO implementations
- 100 for at least 10 correct TODO implementations
- 110 for all 12 correct TODO implementations
