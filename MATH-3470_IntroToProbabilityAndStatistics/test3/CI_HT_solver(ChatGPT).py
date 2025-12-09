import math
from scipy.stats import norm, t, chi2

def CI_mean():
    print("\n--- Confidence Interval for Mean ---")
    xbar = float(input("Sample mean x̄: "))
    n = int(input("Sample size n: "))
    sigma_known = input("Is σ known? (y/n): ").lower()

    alpha = float(input("Alpha (e.g., 0.05): "))

    if sigma_known == "y":
        sigma = float(input("Population σ: "))
        z = norm.ppf(1 - alpha/2)
        margin = z * sigma / math.sqrt(n)
    else:
        s = float(input("Sample standard deviation s: "))
        tcrit = t.ppf(1 - alpha/2, n - 1)
        margin = tcrit * s / math.sqrt(n)

    L = xbar - margin
    U = xbar + margin

    print(f"\nCI = ({L:.4f}, {U:.4f})")


def CI_proportion():
    print("\n--- Confidence Interval for Proportion ---")
    x = int(input("Number of successes x: "))
    n = int(input("Sample size n: "))
    alpha = float(input("Alpha (e.g., 0.05): "))

    p_hat = x / n
    z = norm.ppf(1 - alpha/2)
    margin = z * math.sqrt(p_hat*(1 - p_hat)/n)

    L = p_hat - margin
    U = p_hat + margin

    print(f"\np̂ = {p_hat:.4f}")
    print(f"CI = ({L:.4f}, {U:.4f})")


def CI_chi_square():
    print("\n--- Confidence Interval for Variance / Standard Deviation (Chi-Square) ---")
    s = float(input("Sample standard deviation s: "))
    n = int(input("Sample size n: "))
    alpha = float(input("Alpha (e.g., 0.05): "))

    df = n - 1
    chi_low = chi2.ppf(alpha/2, df)
    chi_high = chi2.ppf(1 - alpha/2, df)

    var_low = (df * s**2) / chi_high
    var_high = (df * s**2) / chi_low

    print(f"\nVariance CI = ({var_low:.4f}, {var_high:.4f})")
    print(f"Std Dev CI = ({math.sqrt(var_low):.4f}, {math.sqrt(var_high):.4f})")


def HT_mean():
    print("\n--- Hypothesis Test for Mean ---")
    xbar = float(input("Sample mean x̄: "))
    mu0 = float(input("Null mean μ₀: "))
    n = int(input("Sample size n: "))
    sigma_known = input("Is σ known? (y/n): ").lower()
    alpha = float(input("Alpha (e.g., 0.05): "))
    tail = input("Tail type (left/right/two): ").lower()

    if sigma_known == "y":
        sigma = float(input("Population σ: "))
        se = sigma / math.sqrt(n)
        test_stat = (xbar - mu0) / se
        dist = "z"
    else:
        s = float(input("Sample standard deviation s: "))
        se = s / math.sqrt(n)
        test_stat = (xbar - mu0) / se
        dist = "t"

    print(f"\nTest statistic ({dist}) = {test_stat:.4f}")

    # p-value
    if dist == "z":
        if tail == "left":
            p = norm.cdf(test_stat)
        elif tail == "right":
            p = 1 - norm.cdf(test_stat)
        else:
            p = 2 * (1 - norm.cdf(abs(test_stat)))
    else:
        df = n - 1
        if tail == "left":
            p = t.cdf(test_stat, df)
        elif tail == "right":
            p = 1 - t.cdf(test_stat, df)
        else:
            p = 2 * (1 - t.cdf(abs(test_stat), df))

    print(f"p-value = {p:.4f}")

    # decision
    if p < alpha:
        print("Decision: Reject H₀")
    else:
        print("Decision: Fail to reject H₀")


def HT_proportion():
    print("\n--- Hypothesis Test for Proportion ---")
    x = int(input("Number of successes x: "))
    n = int(input("Sample size n: "))
    p0 = float(input("Null proportion p₀: "))
    alpha = float(input("Alpha (e.g., 0.05): "))
    tail = input("Tail type (left/right/two): ").lower()

    p_hat = x/n
    se = math.sqrt(p0*(1-p0)/n)
    z = (p_hat - p0) / se

    print(f"\np̂ = {p_hat:.4f}")
    print(f"z = {z:.4f}")

    if tail == "left":
        p = norm.cdf(z)
    elif tail == "right":
        p = 1 - norm.cdf(z)
    else:
        p = 2 * (1 - norm.cdf(abs(z)))

    print(f"p-value = {p:.4f}")

    if p < alpha:
        print("Decision: Reject H₀")
    else:
        print("Decision: Fail to reject H₀")


def main_menu():
    while True:
        print("\n==============================")
        print(" Probability & Stats Toolkit ")
        print("==============================")
        print("1. CI_Mean")
        print("2. CI_Proportion")
        print("3. CI_ChiSquare (variance/std dev)")
        print("4. HT_Mean")
        print("5. HT_Proportion")
        print("6. Exit")

        choice = input("Choose an option: ")

        if choice == "1":
            CI_mean()
        elif choice == "2":
            CI_proportion()
        elif choice == "3":
            CI_chi_square()
        elif choice == "4":
            HT_mean()
        elif choice == "5":
            HT_proportion()
        elif choice == "6":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Try again.")


if __name__ == "__main__":
    main_menu()
