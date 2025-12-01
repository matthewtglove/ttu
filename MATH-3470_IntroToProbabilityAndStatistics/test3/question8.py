import math
from mpmath import quad, sqrt, pi, exp

# -------------------------------
# Inputs (your exact values)
# -------------------------------
confidence_level = 0.97
margin_of_error = 0.04
p = 0.5                   # Use 0.5 to maximize required n
alpha = 1 - confidence_level
alpha_over_2 = alpha / 2

# -------------------------------
# Function to compute z critical
# -------------------------------
def phi_inv(prob):
    # Inverse CDF of standard normal using bisection
    lo, hi = -10, 10
    for _ in range(100):
        mid = (lo + hi) / 2
        if norm_cdf(mid) < prob:
            lo = mid
        else:
            hi = mid
    return (lo + hi) / 2

def norm_cdf(x):
    return 0.5 * (1 + math.erf(x / math.sqrt(2)))

# -------------------------------
# Compute z critical for 97% CI
# -------------------------------
z = phi_inv(1 - alpha_over_2)

# -------------------------------
# Sample size formula
# n = (z^2 * p * (1 - p)) / E^2
# -------------------------------
n = (z**2 * p * (1 - p)) / (margin_of_error**2)
n_ceiling = math.ceil(n)

# -------------------------------
# Output
# -------------------------------
print(f"Confidence level: {confidence_level*100:.1f}%")
print(f"Margin of error: {margin_of_error}")
print(f"z-critical value: {z:.4f}")
print(f"Calculated n (unrounded): {n:.4f}")
print(f"Required sample size n (rounded up): {n_ceiling}")
