import numpy as np
from scipy.stats import norm, t, chi2, f
import math

# --- HYPOTHESIS TESTS (HT) ---

def HT_Mean(sample_mean, hypothesized_mean, sample_std, sample_n, alpha, tail_type='two'):
    """
    Performs a one-sample t-test for the population mean (mu).

    Assumes population standard deviation (sigma) is unknown, thus using the
    t-distribution. For large n (e.g., > 30), t-test approximates the Z-test.

    Args:
        sample_mean (float): The mean of the sample data (x_bar).
        hypothesized_mean (float): The value of the mean under the null hypothesis (mu_0).
        sample_std (float): The standard deviation of the sample data (s).
        sample_n (int): The size of the sample (n).
        alpha (float): The significance level (e.g., 0.05).
        tail_type (str): 'two', 'left', or 'right' for the alternative hypothesis.

    Returns:
        dict: Test statistic (t_stat), p-value, and critical value(s).
    """
    df = sample_n - 1
    # Calculate the test statistic (t-score)
    se = sample_std / np.sqrt(sample_n)
    t_stat = (sample_mean - hypothesized_mean) / se

    # Calculate the p-value based on the tail type
    if tail_type == 'two':
        p_value = 2 * t.sf(abs(t_stat), df)
        critical_value = t.ppf(1 - alpha / 2, df)
        cvs = (f"-{critical_value:.4f}", f"+{critical_value:.4f}")
    elif tail_type == 'left':
        p_value = t.cdf(t_stat, df)
        critical_value = t.ppf(alpha, df)
        cvs = (f"{critical_value:.4f}",)
    elif tail_type == 'right':
        p_value = t.sf(t_stat, df)
        critical_value = t.ppf(1 - alpha, df)
        cvs = (f"{critical_value:.4f}",)
    else:
        raise ValueError("tail_type must be 'two', 'left', or 'right'")

    return {
        "test_type": "One-Sample T-Test for Mean",
        "t_stat": t_stat,
        "p_value": p_value,
        "critical_value(s)": cvs,
        "reject_null": p_value < alpha
    }


def HT_Proportion(x, sample_n, hypothesized_proportion, alpha, tail_type='two'):
    """
    Performs a one-sample Z-test for the population proportion (p).

    Args:
        x (int): The number of successes in the sample.
        sample_n (int): The size of the sample (n).
        hypothesized_proportion (float): The value of the proportion under H0 (p_0).
        alpha (float): The significance level (e.g., 0.05).
        tail_type (str): 'two', 'left', or 'right'.

    Returns:
        dict: Test statistic (z_stat), p-value, and critical value(s).
    """
    sample_p = x / sample_n

    # Check for Normal approximation conditions
    if not (sample_n * hypothesized_proportion >= 10 and sample_n * (1 - hypothesized_proportion) >= 10):
        print("Warning: Normal approximation conditions (np >= 10 and n(1-p) >= 10) may not be met.")

    # Calculate the standard error using the hypothesized proportion
    se_p = np.sqrt(hypothesized_proportion * (1 - hypothesized_proportion) / sample_n)

    # Calculate the test statistic (Z-score)
    z_stat = (sample_p - hypothesized_proportion) / se_p

    # Calculate the p-value based on the tail type (using standard normal distribution)
    if tail_type == 'two':
        p_value = 2 * norm.sf(abs(z_stat))
        critical_value = norm.ppf(1 - alpha / 2)
        cvs = (f"-{critical_value:.4f}", f"+{critical_value:.4f}")
    elif tail_type == 'left':
        p_value = norm.cdf(z_stat)
        critical_value = norm.ppf(alpha)
        cvs = (f"{critical_value:.4f}",)
    elif tail_type == 'right':
        p_value = norm.sf(z_stat)
        critical_value = norm.ppf(1 - alpha)
        cvs = (f"{critical_value:.4f}",)
    else:
        raise ValueError("tail_type must be 'two', 'left', or 'right'")

    return {
        "test_type": "One-Sample Z-Test for Proportion",
        "z_stat": z_stat,
        "p_value": p_value,
        "critical_value(s)": cvs,
        "reject_null": p_value < alpha
    }

def HT_Ftest_Variances(s1_sq, n1, s2_sq, n2, alpha, tail_type='two'):
    """
    Performs an F-test to compare two population variances (sigma1^2 vs sigma2^2).

    Assumes the ratio is s1^2 / s2^2. F-stat must be > 1.0.

    Args:
        s1_sq (float): Sample variance of group 1 (s1^2).
        n1 (int): Sample size of group 1.
        s2_sq (float): Sample variance of group 2 (s2^2).
        n2 (int): Sample size of group 2.
        alpha (float): The significance level (e.g., 0.05).
        tail_type (str): 'two', 'left', or 'right'.

    Returns:
        dict: Test statistic (F_stat), p-value, and critical value(s).
    """
    df1 = n1 - 1
    df2 = n2 - 1

    # F-statistic is the ratio of sample variances (s1^2 / s2^2)
    f_stat = s1_sq / s2_sq

    # Calculate p-value and critical value(s)
    if tail_type == 'two':
        # Since we use the F distribution table where F > 1,
        # we calculate the P-value for the side where F_stat falls (always > 1).
        p_value_one_tail = f.sf(f_stat, df1, df2)
        p_value = 2 * p_value_one_tail # Double the P-value for the two-tailed test

        # Critical values for a two-tailed test
        # Note: The test assumes the larger variance is always in the numerator for calculation
        # to ensure F_stat > 1, so the F-stat is only compared to the upper CV.
        f_crit_upper = f.ppf(1 - alpha / 2, df1, df2)
        f_crit_lower = f.ppf(alpha / 2, df1, df2) # Included for completeness
        cvs = (f"{f_crit_lower:.4f}", f"{f_crit_upper:.4f}")

    elif tail_type == 'right': # H_a: sigma1^2 > sigma2^2
        p_value = f.sf(f_stat, df1, df2)
        f_crit = f.ppf(1 - alpha, df1, df2)
        cvs = (f"{f_crit:.4f}",)

    elif tail_type == 'left': # H_a: sigma1^2 < sigma2^2
        p_value = f.cdf(f_stat, df1, df2)
        f_crit = f.ppf(alpha, df1, df2)
        cvs = (f"{f_crit:.4f}",)

    else:
        raise ValueError("tail_type must be 'two', 'left', or 'right'")

    return {
        "test_type": "F-Test for Two Variances (s1^2 / s2^2)",
        "f_stat": f_stat,
        "p_value": p_value,
        "critical_value(s)": cvs,
        "reject_null": p_value < alpha
    }


# --- CONFIDENCE INTERVALS (CI) ---

def CI_Mean(sample_mean, sample_std, sample_n, confidence_level):
    """
    Calculates the T-interval for the population mean (mu).

    Assumes population standard deviation (sigma) is unknown.

    Args:
        sample_mean (float): The mean of the sample data (x_bar).
        sample_std (float): The standard deviation of the sample data (s).
        sample_n (int): The size of the sample (n).
        confidence_level (float): The confidence level (e.g., 0.95).

    Returns:
        tuple: (lower_bound, upper_bound) of the confidence interval.
    """
    alpha = 1 - confidence_level
    df = sample_n - 1

    # Find the critical t-value (t_alpha/2)
    # Use survival function (sf) for upper tail or ppf(1 - alpha/2)
    t_crit = t.ppf(1 - alpha / 2, df)

    # Calculate the margin of error (ME)
    se = sample_std / np.sqrt(sample_n)
    margin_of_error = t_crit * se

    # Calculate the confidence interval bounds
    lower_bound = sample_mean - margin_of_error
    upper_bound = sample_mean + margin_of_error

    return (round(lower_bound, 4), round(upper_bound, 4))


def CI_Proportion(x, sample_n, confidence_level):
    """
    Calculates the Z-interval (Wald or Standard) for the population proportion (p).

    Args:
        x (int): The number of successes in the sample.
        sample_n (int): The size of the sample (n).
        confidence_level (float): The confidence level (e.g., 0.95).

    Returns:
        tuple: (lower_bound, upper_bound) of the confidence interval.
    """
    sample_p = x / sample_n
    sample_q = 1 - sample_p
    alpha = 1 - confidence_level

    # Find the critical z-value (z_alpha/2)
    z_crit = norm.ppf(1 - alpha / 2)

    # Calculate the margin of error (ME) using sample proportion
    se_p = np.sqrt(sample_p * sample_q / sample_n)
    margin_of_error = z_crit * se_p

    # Calculate the confidence interval bounds
    lower_bound = sample_p - margin_of_error
    upper_bound = sample_p + margin_of_error

    # Note: Bounds are often capped at 0 and 1
    return (max(0, round(lower_bound, 4)), min(1, round(upper_bound, 4)))


def CI_ChiSquare(sample_std, sample_n, confidence_level):
    """
    Calculates the Chi-Square interval for the population variance (sigma^2).

    Args:
        sample_std (float): The standard deviation of the sample data (s).
        sample_n (int): The size of the sample (n).
        confidence_level (float): The confidence level (e.g., 0.95).

    Returns:
        tuple: (lower_bound_variance, upper_bound_variance) of the CI for sigma^2.
    """
    alpha = 1 - confidence_level
    df = sample_n - 1
    sample_variance = sample_std ** 2
    sum_of_squares = df * sample_variance

    # Find the critical Chi-Square values
    # ChiSq_R (right tail): uses alpha / 2
    chi2_R = chi2.ppf(1 - alpha / 2, df)
    # ChiSq_L (left tail): uses 1 - alpha / 2
    chi2_L = chi2.ppf(alpha / 2, df)

    # Calculate the confidence interval bounds for variance (sigma^2)
    lower_bound_variance = sum_of_squares / chi2_R
    upper_bound_variance = sum_of_squares / chi2_L

    return (round(lower_bound_variance, 4), round(upper_bound_variance, 4))


# --- INTERACTIVE MENU AND INPUT FUNCTIONS ---

def get_float_input(prompt):
    """Safely gets a float input from the user."""
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a number.")

def get_int_input(prompt):
    """Safely gets an integer input from the user."""
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a whole number.")

def get_tail_type():
    """Gets the tail type for hypothesis tests."""
    while True:
        tail = input("Enter tail type ('two', 'left', or 'right'): ").lower().strip()
        if tail in ['two', 'left', 'right']:
            return tail
        print("Invalid tail type. Please enter 'two', 'left', or 'right'.")


def run_ht_mean():
    print("\n--- Running HT_Mean (One-Sample T-Test) ---")
    s_mean = get_float_input("Enter Sample Mean (x̄): ")
    h_mean = get_float_input("Enter Hypothesized Mean (μ₀): ")
    s_std = get_float_input("Enter Sample Standard Deviation (s): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    alpha = get_float_input("Enter Significance Level (α, e.g., 0.05): ")
    tail = get_tail_type()

    result = HT_Mean(s_mean, h_mean, s_std, s_n, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items():
        print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")


def run_ht_proportion():
    print("\n--- Running HT_Proportion (One-Sample Z-Test) ---")
    x = get_int_input("Enter Number of Successes (x): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    h_p = get_float_input("Enter Hypothesized Proportion (p₀): ")
    alpha = get_float_input("Enter Significance Level (α, e.g., 0.05): ")
    tail = get_tail_type()

    result = HT_Proportion(x, s_n, h_p, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items():
        print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")


def run_ht_ftest_variances():
    print("\n--- Running HT_Ftest_Variances (Two-Sample F-Test) ---")
    s1_sq = get_float_input("Enter Sample Variance 1 (s₁²): ")
    n1 = get_int_input("Enter Sample Size 1 (n₁): ")
    s2_sq = get_float_input("Enter Sample Variance 2 (s₂²): ")
    n2 = get_int_input("Enter Sample Size 2 (n₂): ")
    alpha = get_float_input("Enter Significance Level (α, e.g., 0.05): ")
    tail = get_tail_type()

    result = HT_Ftest_Variances(s1_sq, n1, s2_sq, n2, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items():
        print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")


def run_ci_mean():
    print("\n--- Running CI_Mean (T-Interval) ---")
    s_mean = get_float_input("Enter Sample Mean (x̄): ")
    s_std = get_float_input("Enter Sample Standard Deviation (s): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    cl = get_float_input("Enter Confidence Level (e.g., 0.95): ")

    lower, upper = CI_Mean(s_mean, s_std, s_n, cl)
    print(f"\n{int(cl*100)}% Confidence Interval for Mean (μ): ({lower}, {upper})")


def run_ci_proportion():
    print("\n--- Running CI_Proportion (Z-Interval) ---")
    x = get_int_input("Enter Number of Successes (x): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    cl = get_float_input("Enter Confidence Level (e.g., 0.95): ")

    lower, upper = CI_Proportion(x, s_n, cl)
    print(f"\n{int(cl*100)}% Confidence Interval for Proportion (p): ({lower}, {upper})")


def run_ci_chi_square():
    print("\n--- Running CI_ChiSquare (Chi-Square Interval for Variance) ---")
    s_std = get_float_input("Enter Sample Standard Deviation (s): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    cl = get_float_input("Enter Confidence Level (e.g., 0.90): ")

    lower, upper = CI_ChiSquare(s_std, s_n, cl)
    print(f"\n{int(cl*100)}% Confidence Interval for Variance (σ²): ({lower}, {upper})")


def main_menu():
    """Displays the menu and handles user selection."""
    functions = {
        '1': ("Hypothesis Test for Mean (HT_Mean)", run_ht_mean),
        '2': ("Hypothesis Test for Proportion (HT_Proportion)", run_ht_proportion),
        '3': ("Hypothesis Test for Variances (HT_Ftest_Variances)", run_ht_ftest_variances),
        '4': ("Confidence Interval for Mean (CI_Mean)", run_ci_mean),
        '5': ("Confidence Interval for Proportion (CI_Proportion)", run_ci_proportion),
        '6': ("Confidence Interval for Variance (CI_ChiSquare)", run_ci_chi_square),
    }

    while True:
        print("\n=======================================================")
        print("          STATISTICAL DISTRIBUTION CALCULATOR          ")
        print("=======================================================")
        print("Choose a function to run:")
        for key, (name, _) in functions.items():
            print(f"  {key}. {name}")
        print("  Q. Quit")
        print("-------------------------------------------------------")

        choice = input("Enter your choice (1-6 or Q): ").strip().upper()

        if choice == 'Q':
            print("\nExiting the calculator. Goodbye!")
            break
        elif choice in functions:
            try:
                # Run the selected function
                functions[choice][1]()
            except Exception as e:
                print(f"\nAn error occurred during calculation: {e}")
        else:
            print(f"Invalid choice: '{choice}'. Please select a number from 1 to 6.")


if __name__ == "__main__":
    main_menu()