import numpy as np
from scipy.stats import norm, t, chi2, f, linregress
import math

# --- HYPOTHESIS TESTS (HT) ---

def HT_Mean(sample_mean, hypothesized_mean, sample_std, sample_n, alpha, tail_type='two'):
    """Performs a one-sample t-test for the population mean (mu)."""
    df = sample_n - 1
    se = sample_std / np.sqrt(sample_n)
    t_stat = (sample_mean - hypothesized_mean) / se

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
    """Performs a one-sample Z-test for the population proportion (p)."""
    sample_p = x / sample_n
    se_p = np.sqrt(hypothesized_proportion * (1 - hypothesized_proportion) / sample_n)
    z_stat = (sample_p - hypothesized_proportion) / se_p

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
    """Performs an F-test to compare two population variances (sigma1^2 vs sigma2^2). Assumes s1^2 is in the numerator."""
    df1 = n1 - 1
    df2 = n2 - 1
    f_stat = s1_sq / s2_sq

    if tail_type == 'two':
        p_value = 2 * f.sf(f_stat, df1, df2)
        f_crit_upper = f.ppf(1 - alpha / 2, df1, df2)
        f_crit_lower = f.ppf(alpha / 2, df1, df2)
        cvs = (f"{f_crit_lower:.4f}", f"{f_crit_upper:.4f}")
    elif tail_type == 'right':
        p_value = f.sf(f_stat, df1, df2)
        f_crit = f.ppf(1 - alpha, df1, df2)
        cvs = (f"{f_crit:.4f}",)
    elif tail_type == 'left':
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


def HT_ChiSquare_Independence(observed_matrix, alpha):
    """
    Performs a Chi-Square Test of Independence on a contingency table.

    Args:
        observed_matrix (list of lists): The contingency table (observed counts).
        alpha (float): The significance level.

    Returns:
        dict: Chi-square statistic, p-value, critical value, and decision.
    """
    observed_matrix = np.array(observed_matrix)
    rows, cols = observed_matrix.shape
    df = (rows - 1) * (cols - 1)

    # Calculate row and column totals
    row_totals = observed_matrix.sum(axis=1)
    col_totals = observed_matrix.sum(axis=0)
    grand_total = observed_matrix.sum()

    # Calculate expected frequencies (E_ij = (R_i * C_j) / N)
    expected_matrix = np.outer(row_totals, col_totals) / grand_total

    # Calculate the Chi-Square test statistic: sum((O - E)^2 / E)
    chi2_stat = np.sum((observed_matrix - expected_matrix)**2 / expected_matrix)

    # Calculate p-value (right-tail test)
    p_value = chi2.sf(chi2_stat, df)

    # Critical value
    critical_value = chi2.ppf(1 - alpha, df)

    return {
        "test_type": "Chi-Square Test of Independence",
        "chi2_stat": chi2_stat,
        "degrees_of_freedom": df,
        "p_value": p_value,
        "critical_value": f"{critical_value:.4f}",
        "reject_null": p_value < alpha
    }


def HT_Two_Sample_Mean(x1_bar, s1, n1, x2_bar, s2, n2, alpha, tail_type='two', equal_variances=False):
    """
    Performs a two-sample t-test for the difference between two means (unpooled/unassumed unequal variances).
    
    NOTE: Using the unpooled (Welch's) t-test unless equal_variances=True.
    The degrees of freedom calculation (df) for Welch's test is complex.
    """
    # Calculate Standard Error
    se = np.sqrt((s1**2 / n1) + (s2**2 / n2))
    
    # Calculate Test Statistic
    t_stat = (x1_bar - x2_bar) / se

    if equal_variances:
        # Pooled variance (s_p^2)
        sp_sq = ((n1-1)*s1**2 + (n2-1)*s2**2) / (n1 + n2 - 2)
        se_pooled = np.sqrt(sp_sq * (1/n1 + 1/n2))
        t_stat = (x1_bar - x2_bar) / se_pooled
        df = n1 + n2 - 2
    else:
        # Welch's T-test degrees of freedom (complex formula for non-integer df)
        numerator = ((s1**2/n1) + (s2**2/n2))**2
        denominator = ((s1**2/n1)**2 / (n1-1)) + ((s2**2/n2)**2 / (n2-1))
        df = math.floor(numerator / denominator)
        
    # Calculate p-value and critical value
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
        "test_type": "Two-Sample T-Test for Mean",
        "t_stat": t_stat,
        "degrees_of_freedom": df,
        "p_value": p_value,
        "critical_value(s)": cvs,
        "reject_null": p_value < alpha
    }


def HT_Two_Sample_Proportion(x1, n1, x2, n2, alpha, tail_type='two'):
    """Performs a two-sample Z-test for the difference between two proportions (p1 - p2)."""
    p1_hat = x1 / n1
    p2_hat = x2 / n2

    # Pooled proportion (used for standard error in hypothesis tests)
    p_bar = (x1 + x2) / (n1 + n2)
    q_bar = 1 - p_bar

    # Standard error for the difference (using pooled proportion)
    se_diff = np.sqrt(p_bar * q_bar * (1/n1 + 1/n2))

    # Calculate Test Statistic (Z-score)
    z_stat = (p1_hat - p2_hat) / se_diff

    # Calculate p-value and critical value
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
        "test_type": "Two-Sample Z-Test for Proportion",
        "z_stat": z_stat,
        "p_value": p_value,
        "critical_value(s)": cvs,
        "reject_null": p_value < alpha
    }


def HT_Correlation_R(r, n, alpha, tail_type='two'):
    """Performs a t-test to determine if the population correlation coefficient (rho) is significantly different from zero."""
    df = n - 2
    
    # Test statistic (t = r / SE_r)
    if n < 3:
        return {"Error": "Sample size must be 3 or greater for correlation test."}
        
    t_stat = r * np.sqrt(df / (1 - r**2))

    # Calculate p-value and critical value
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
        "test_type": "T-Test for Correlation Coefficient (ρ)",
        "t_stat": t_stat,
        "degrees_of_freedom": df,
        "p_value": p_value,
        "critical_value(s)": cvs,
        "reject_null": p_value < alpha
    }


# --- CONFIDENCE INTERVALS (CI) ---

def CI_Mean(sample_mean, sample_std, sample_n, confidence_level):
    """Calculates the T-interval for the population mean (mu)."""
    alpha = 1 - confidence_level
    df = sample_n - 1
    t_crit = t.ppf(1 - alpha / 2, df)
    se = sample_std / np.sqrt(sample_n)
    margin_of_error = t_crit * se
    lower_bound = sample_mean - margin_of_error
    upper_bound = sample_mean + margin_of_error
    return (round(lower_bound, 4), round(upper_bound, 4))


def CI_Proportion(x, sample_n, confidence_level):
    """Calculates the Z-interval (Wald or Standard) for the population proportion (p)."""
    sample_p = x / sample_n
    sample_q = 1 - sample_p
    alpha = 1 - confidence_level
    z_crit = norm.ppf(1 - alpha / 2)
    se_p = np.sqrt(sample_p * sample_q / sample_n)
    margin_of_error = z_crit * se_p
    lower_bound = sample_p - margin_of_error
    upper_bound = sample_p + margin_of_error
    return (max(0, round(lower_bound, 4)), min(1, round(upper_bound, 4)))


def CI_ChiSquare(sample_std, sample_n, confidence_level):
    """Calculates the Chi-Square interval for the population variance (sigma^2)."""
    alpha = 1 - confidence_level
    df = sample_n - 1
    sample_variance = sample_std ** 2
    sum_of_squares = df * sample_variance
    chi2_R = chi2.ppf(1 - alpha / 2, df)
    chi2_L = chi2.ppf(alpha / 2, df)
    lower_bound_variance = sum_of_squares / chi2_R
    upper_bound_variance = sum_of_squares / chi2_L

    return (round(lower_bound_variance, 4), round(upper_bound_variance, 4))


def CI_Two_Sample_Mean(x1_bar, s1, n1, x2_bar, s2, n2, confidence_level, equal_variances=False):
    """
    Calculates the T-interval for the difference between two means.
    
    NOTE: Uses Welch's T-interval (unpooled) by default.
    """
    alpha = 1 - confidence_level

    if equal_variances:
        # Pooled variance (s_p^2)
        sp_sq = ((n1-1)*s1**2 + (n2-1)*s2**2) / (n1 + n2 - 2)
        se_pooled = np.sqrt(sp_sq * (1/n1 + 1/n2))
        df = n1 + n2 - 2
        se = se_pooled
    else:
        # Welch's T-test degrees of freedom (complex formula for non-integer df)
        numerator = ((s1**2/n1) + (s2**2/n2))**2
        denominator = ((s1**2/n1)**2 / (n1-1)) + ((s2**2/n2)**2 / (n2-1))
        df = math.floor(numerator / denominator)
        se = np.sqrt((s1**2 / n1) + (s2**2 / n2))
        
    t_crit = t.ppf(1 - alpha / 2, df)
    
    # Margin of Error
    margin_of_error = t_crit * se

    # CI bounds for (mu1 - mu2)
    diff = x1_bar - x2_bar
    lower_bound = diff - margin_of_error
    upper_bound = diff + margin_of_error

    return (round(lower_bound, 4), round(upper_bound, 4), df)


def CI_Two_Sample_Proportion(x1, n1, x2, n2, confidence_level):
    """Calculates the Z-interval for the difference between two proportions (p1 - p2)."""
    p1_hat = x1 / n1
    p2_hat = x2 / n2
    q1_hat = 1 - p1_hat
    q2_hat = 1 - p2_hat
    alpha = 1 - confidence_level

    # Standard error for the difference (using sample proportions)
    se_diff = np.sqrt((p1_hat * q1_hat / n1) + (p2_hat * q2_hat / n2))

    # Critical Z-value
    z_crit = norm.ppf(1 - alpha / 2)
    
    # Margin of Error
    margin_of_error = z_crit * se_diff

    # CI bounds for (p1 - p2)
    diff = p1_hat - p2_hat
    lower_bound = diff - margin_of_error
    upper_bound = diff + margin_of_error

    return (round(lower_bound, 4), round(upper_bound, 4))


# --- REGRESSION AND CORRELATION ---

def Calc_Regression_Line(x_data, y_data):
    """
    Calculates the slope (b1), intercept (b0), and correlation coefficient (r)
    for the least-squares regression line (y-hat = b0 + b1*x).
    
    Args:
        x_data (list/array): Independent variable data.
        y_data (list/array): Dependent variable data.
    """
    x_data = np.array(x_data)
    y_data = np.array(y_data)
    
    # Use scipy's built-in function which provides all parameters
    slope, intercept, r_value, p_value, std_err = linregress(x_data, y_data)
    
    return {
        "slope_b1": round(slope, 4),
        "intercept_b0": round(intercept, 4),
        "correlation_r": round(r_value, 4),
        "regression_equation": f"ŷ = {round(intercept, 4)} + {round(slope, 4)}x"
    }


# --- INTERACTIVE MENU AND INPUT FUNCTIONS (UPDATED) ---

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

def get_list_input(prompt):
    """Safely gets a comma-separated list of numbers."""
    while True:
        try:
            data_str = input(prompt)
            return [float(x.strip()) for x in data_str.split(',')]
        except ValueError:
            print("Invalid input. Please enter numbers separated by commas (e.g., 1.5, 2.0, 3.5).")

def get_matrix_input(rows, cols):
    """Safely gets matrix input for Chi-Square Independence test."""
    matrix = []
    print(f"Enter {rows} rows of data, separated by commas:")
    for i in range(rows):
        while True:
            row_str = input(f"Row {i+1} ({cols} values): ")
            try:
                row = [int(x.strip()) for x in row_str.split(',')]
                if len(row) == cols:
                    matrix.append(row)
                    break
                else:
                    print(f"Error: Row must contain exactly {cols} values.")
            except ValueError:
                print("Invalid input. Please enter whole numbers separated by commas.")
    return matrix


# --- RUNNER FUNCTIONS ---

def run_ht_mean():
    print("\n--- Running HT_Mean (One-Sample T-Test) ---")
    s_mean = get_float_input("Enter Sample Mean (x̄): ")
    h_mean = get_float_input("Enter Hypothesized Mean (μ₀): ")
    s_std = get_float_input("Enter Sample Standard Deviation (s): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    alpha = get_float_input("Enter Significance Level (α): ")
    tail = get_tail_type()
    result = HT_Mean(s_mean, h_mean, s_std, s_n, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")

def run_ht_proportion():
    print("\n--- Running HT_Proportion (One-Sample Z-Test) ---")
    x = get_int_input("Enter Number of Successes (x): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    h_p = get_float_input("Enter Hypothesized Proportion (p₀): ")
    alpha = get_float_input("Enter Significance Level (α): ")
    tail = get_tail_type()
    result = HT_Proportion(x, s_n, h_p, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")

def run_ht_ftest_variances():
    print("\n--- Running HT_Ftest_Variances (Two-Sample F-Test) ---")
    s1_sq = get_float_input("Enter Sample Variance 1 (s₁²): ")
    n1 = get_int_input("Enter Sample Size 1 (n₁): ")
    s2_sq = get_float_input("Enter Sample Variance 2 (s₂²): ")
    n2 = get_int_input("Enter Sample Size 2 (n₂): ")
    alpha = get_float_input("Enter Significance Level (α): ")
    tail = get_tail_type()
    result = HT_Ftest_Variances(s1_sq, n1, s2_sq, n2, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")

def run_ht_chi_square_independence():
    print("\n--- Running Chi-Square Test of Independence ---")
    rows = get_int_input("Enter number of rows in the contingency table: ")
    cols = get_int_input("Enter number of columns in the contingency table: ")
    matrix = get_matrix_input(rows, cols)
    alpha = get_float_input("Enter Significance Level (α): ")
    result = HT_ChiSquare_Independence(matrix, alpha)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")
    
def run_ht_two_sample_mean():
    print("\n--- Running HT_Two_Sample_Mean (Two-Sample T-Test) ---")
    print("--- Sample 1 ---")
    x1_bar = get_float_input("Enter Sample Mean 1 (x̄₁): ")
    s1 = get_float_input("Enter Sample Std Dev 1 (s₁): ")
    n1 = get_int_input("Enter Sample Size 1 (n₁): ")
    print("--- Sample 2 ---")
    x2_bar = get_float_input("Enter Sample Mean 2 (x̄₂): ")
    s2 = get_float_input("Enter Sample Std Dev 2 (s₂): ")
    n2 = get_int_input("Enter Sample Size 2 (n₂): ")
    
    alpha = get_float_input("Enter Significance Level (α): ")
    tail = get_tail_type()
    
    # Simple check for equality assumption (can be determined by F-test first)
    equal_var_input = input("Assume Equal Variances? (y/n, 'n' runs Welch's test): ").lower().strip()
    equal_variances = equal_var_input == 'y'

    result = HT_Two_Sample_Mean(x1_bar, s1, n1, x2_bar, s2, n2, alpha, tail, equal_variances)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")

def run_ht_two_sample_proportion():
    print("\n--- Running HT_Two_Sample_Proportion (Two-Sample Z-Test) ---")
    print("--- Sample 1 ---")
    x1 = get_int_input("Enter Successes 1 (x₁): ")
    n1 = get_int_input("Enter Sample Size 1 (n₁): ")
    print("--- Sample 2 ---")
    x2 = get_int_input("Enter Successes 2 (x₂): ")
    n2 = get_int_input("Enter Sample Size 2 (n₂): ")
    
    alpha = get_float_input("Enter Significance Level (α): ")
    tail = get_tail_type()

    result = HT_Two_Sample_Proportion(x1, n1, x2, n2, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")

def run_ht_correlation_r():
    print("\n--- Running T-Test for Correlation Coefficient ($\rho$) ---")
    r = get_float_input("Enter Sample Correlation Coefficient (r): ")
    n = get_int_input("Enter Sample Size (n): ")
    alpha = get_float_input("Enter Significance Level (α): ")
    tail = get_tail_type()
    
    result = HT_Correlation_R(r, n, alpha, tail)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")


def run_ci_mean():
    print("\n--- Running CI_Mean (One-Sample T-Interval) ---")
    s_mean = get_float_input("Enter Sample Mean (x̄): ")
    s_std = get_float_input("Enter Sample Standard Deviation (s): ")
    s_n = get_int_input("Enter Sample Size (n): ")
    cl = get_float_input("Enter Confidence Level (e.g., 0.95): ")
    lower, upper = CI_Mean(s_mean, s_std, s_n, cl)
    print(f"\n{int(cl*100)}% Confidence Interval for Mean (μ): ({lower}, {upper})")

def run_ci_proportion():
    print("\n--- Running CI_Proportion (One-Sample Z-Interval) ---")
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

def run_ci_two_sample_mean():
    print("\n--- Running CI_Two_Sample_Mean (Two-Sample T-Interval) ---")
    print("--- Sample 1 ---")
    x1_bar = get_float_input("Enter Sample Mean 1 (x̄₁): ")
    s1 = get_float_input("Enter Sample Std Dev 1 (s₁): ")
    n1 = get_int_input("Enter Sample Size 1 (n₁): ")
    print("--- Sample 2 ---")
    x2_bar = get_float_input("Enter Sample Mean 2 (x̄₂): ")
    s2 = get_float_input("Enter Sample Std Dev 2 (s₂): ")
    n2 = get_int_input("Enter Sample Size 2 (n₂): ")
    cl = get_float_input("Enter Confidence Level (e.g., 0.95): ")
    
    # Assumption is critical for CI calculation
    equal_var_input = input("Assume Equal Variances? (y/n, 'n' runs Welch's test): ").lower().strip()
    equal_variances = equal_var_input == 'y'

    lower, upper, df = CI_Two_Sample_Mean(x1_bar, s1, n1, x2_bar, s2, n2, cl, equal_variances)
    print(f"\nDegrees of Freedom (df): {df}")
    print(f"{int(cl*100)}% Confidence Interval for Difference in Means (μ₁ - μ₂): ({lower}, {upper})")

def run_ci_two_sample_proportion():
    print("\n--- Running CI_Two_Sample_Proportion (Two-Sample Z-Interval) ---")
    print("--- Sample 1 ---")
    x1 = get_int_input("Enter Successes 1 (x₁): ")
    n1 = get_int_input("Enter Sample Size 1 (n₁): ")
    print("--- Sample 2 ---")
    x2 = get_int_input("Enter Successes 2 (x₂): ")
    n2 = get_int_input("Enter Sample Size 2 (n₂): ")
    cl = get_float_input("Enter Confidence Level (e.g., 0.95): ")

    lower, upper = CI_Two_Sample_Proportion(x1, n1, x2, n2, cl)
    print(f"\n{int(cl*100)}% Confidence Interval for Difference in Proportions (p₁ - p₂): ({lower}, {upper})")


def run_calc_regression_line():
    print("\n--- Running Calc_Regression_Line ---")
    x_data = get_list_input("Enter X data (e.g., 10, 20, 30): ")
    y_data = get_list_input("Enter Y data (e.g., 5, 8, 12): ")
    
    if len(x_data) != len(y_data) or len(x_data) < 2:
        print("Error: X and Y lists must have the same size and at least 2 points.")
        return

    result = Calc_Regression_Line(x_data, y_data)
    print("\n--- RESULTS ---")
    for key, value in result.items(): print(f"{key.replace('_', ' ').title()}: {value}")
    print("---------------")


def main_menu():
    """Displays the menu and handles user selection."""
    functions = {
        # Original 6
        '1': ("HT_Mean (One-Sample T-Test)", run_ht_mean),
        '2': ("HT_Proportion (One-Sample Z-Test)", run_ht_proportion),
        '3': ("HT_Ftest_Variances (Two-Sample F-Test)", run_ht_ftest_variances),
        '4': ("CI_Mean (One-Sample T-Interval)", run_ci_mean),
        '5': ("CI_Proportion (One-Sample Z-Interval)", run_ci_proportion),
        '6': ("CI_ChiSquare (Variance CI)", run_ci_chi_square),
        # New Additions
        '7': ("HT_Two_Sample_Mean", run_ht_two_sample_mean),
        '8': ("HT_Two_Sample_Proportion", run_ht_two_sample_proportion),
        '9': ("CI_Two_Sample_Mean", run_ci_two_sample_mean),
        '10': ("CI_Two_Sample_Proportion", run_ci_two_sample_proportion),
        '11': ("HT_ChiSquare_Independence (Contingency Table)", run_ht_chi_square_independence),
        '12': ("Calc_Regression_Line (r, b0, b1)", run_calc_regression_line),
        '13': ("HT_Correlation_R (Test for $\\rho$)", run_ht_correlation_r),
    }

    while True:
        print("\n=======================================================")
        print("          STATISTICAL DISTRIBUTION CALCULATOR          ")
        print("=======================================================")
        print("--- CORE INFERENTIAL TESTS ---")
        print("  1. Hypothesis Test for Mean (HT_Mean)")
        print("  2. Hypothesis Test for Proportion (HT_Proportion)")
        print("  3. Hypothesis Test for Variances (HT_Ftest_Variances)")
        print("  4. Confidence Interval for Mean (CI_Mean)")
        print("  5. Confidence Interval for Proportion (CI_Proportion)")
        print("  6. Confidence Interval for Variance (CI_ChiSquare)")
        print("--- TWO-SAMPLE TESTS ---")
        print("  7. Hypothesis Test for $\\mu_1 - \\mu_2$ (HT_Two_Sample_Mean)")
        print("  8. Hypothesis Test for $p_1 - p_2$ (HT_Two_Sample_Proportion)")
        print("  9. Confidence Interval for $\\mu_1 - \\mu_2$ (CI_Two_Sample_Mean)")
        print(" 10. Confidence Interval for $p_1 - p_2$ (CI_Two_Sample_Proportion)")
        print("--- NON-PARAMETRIC / REGRESSION ---")
        print(" 11. Chi-Square Test of Independence")
        print(" 12. Calculate Regression Line (r, $\\hat{y}=b_0+b_1x$)")
        print(" 13. Test for Correlation ($\rho$) Significance")
        print("-------------------------------------------------------")
        print("  Q. Quit")
        print("-------------------------------------------------------")

        choice = input("Enter your choice (1-13 or Q): ").strip().upper()

        if choice == 'Q':
            print("\nExiting the calculator. Goodbye!")
            break
        elif choice in functions:
            try:
                functions[choice][1]()
            except Exception as e:
                print(f"\nAn error occurred during calculation: {e}")
        else:
            print(f"Invalid choice: '{choice}'. Please select a number from 1 to 13.")


if __name__ == "__main__":
    main_menu()