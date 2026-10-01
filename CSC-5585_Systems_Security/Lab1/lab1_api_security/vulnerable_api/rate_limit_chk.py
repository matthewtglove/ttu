import requests
import time

# change the port to 5001 for secure implementation
URL = "http://127.0.0.1:5000/api/login"

TOTAL_REQUESTS = 1000

payload_wrong = {
    "username": "alice",
    "password": "wrong-password"
}

payload_correct = {
    "username": "alice",
    "password": "alicepw"
}

success = 0
full_success = 0
rate_limited = 0
other_errors = 0

start = time.time()

for i in range(TOTAL_REQUESTS):

    response = requests.post(
        URL,
        json=payload_correct
    )

    if response.status_code == 401:
        success += 1

    elif response.status_code == 200:
        full_success += 1

    elif response.status_code == 429:
        rate_limited += 1

        # Print the first few rate-limit responses.
        if rate_limited <= 5:
            print(
                f"[{i + 1}] 429 Too Many Requests"
            )

    else:
        other_errors += 1

    # Don't print all 1000 requests.
    if (i + 1) % 100 == 0:
        print(
            f"Sent {i + 1}/{TOTAL_REQUESTS} requests"
        )


elapsed = time.time() - start


print()
print("=" * 50)
print("RATE LIMIT TEST RESULTS")
print("=" * 50)

print(
    f"Total requests: {TOTAL_REQUESTS}"
)

print(
    f"401 responses:   {success}"
)

print(
    f"200 responses:   {full_success}"
)

print(
    f"429 responses:   {rate_limited}"
)

print(
    f"Other responses: {other_errors}"
)

print(
    f"Elapsed time:    {elapsed:.2f} seconds"
)

print("=" * 50)