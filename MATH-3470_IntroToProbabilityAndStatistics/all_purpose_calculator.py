import math
import numpy as np
import scipy.stats as stats
from collections import Counter

# ==============================================================================
# 1. Descriptive Statistics Calculator
#    Requires a list of numerical data (data_list) for all functions
# ==============================================================================

def calculate_mean(data_list):
    """1. Mean: Calculates the average of the dataset."""
    if not data_list:
        return 0
    return sum(data_list) / len(data_list)

def calculate_variance(data_list, sample=True):
    """
    2. Variance: Calculates the variance of the dataset.
    If sample=True, uses (n-1) in the denominator (sample variance).
    If sample=False, uses (n) in the denominator (population variance).
    """
    n = len(data_list)
    if n < 2 and sample:
        return 0  # Cannot calculate sample variance for n < 2
    
    mean = calculate_mean(data_list)
    squared_diffs = [(x - mean) ** 2 for x in data_list]
    
    if sample:
        # Sample Variance (dividing by n-1)
        return sum(squared_diffs) / (n - 1)
    else:
        # Population Variance (dividing by n)
        return sum(squared_diffs) / n

def calculate_std_dev(data_list, sample=True):
    """3. Sample Standard Deviation: Calculates the standard deviation."""
    variance = calculate_variance(data_list, sample=sample)
    return math.sqrt(variance)

def calculate_median_quartiles(data_list):
    """4. Median and Quartiles: Calculates Q1, Median (Q2), and Q3."""
    # Using numpy's percentile calculation which is standard
    data_array = np.array(data_list)
    q1 = np.percentile(data_array, 25, method='midpoint')
    median = np.percentile(data_array, 50, method='midpoint')
    q3 = np.percentile(data_array, 75, method='midpoint')
    return q1, median, q3

def calculate_five_number_summary(data_list):
    """5. Five Number Summary: (Min, Q1, Median, Q3, Max)"""
    if not data_list:
        return (None, None, None, None, None)
    sorted_data = sorted(data_list)
    minimum = sorted_data[0]
    maximum = sorted_data[-1]
    q1, median, q3 = calculate_median_quartiles(data_list)
    return minimum, q1, median, q3, maximum

def calculate_range_iqr(data_list):
    """6. Range and Interquartile Range (IQR)"""
    if not data_list:
        return (None, None)
    
    minimum, q1, _, q3, maximum = calculate_five_number_summary(data_list)
    
    data_range = maximum - minimum
    iqr = q3 - q1
    return data_range, iqr


# ==============================================================================
# 2. Probability Tools
# ==============================================================================

def calculate_combinations(n, k):
    """1. Combinations: Calculates the number of combinations C(n, k)."""
    if k < 0 or k > n:
        return 0
    # math.comb is available in Python 3.8+ and is efficient
    return math.comb(n, k)


# ==============================================================================
# 3. Discrete Probability Distributions
# ==============================================================================

def geometric_mean(p):
    """1. Geometric Mean: Calculates E[X] for a Geometric Distribution."""
    if p <= 0 or p > 1:
        return "Error: Probability p must be between 0 and 1."
    return 1 / p

def binomial_probability(k, n, p, cumulative=False):
    """
    2. Binomial Probability: Calculates P(X=k) or P(X <= k).
    k: number of successes, n: number of trials, p: probability of success.
    """
    if p < 0 or p > 1 or n < 0 or k < 0 or k > n:
        return "Error: Invalid parameters for Binomial distribution."

    if cumulative:
        return stats.binom.cdf(k, n, p)
    else:
        return stats.binom.pmf(k, n, p)

def poisson_probability(k, lambda_val, cumulative=False):
    """
    3. Poisson Probability: Calculates P(X=k) or P(X <= k).
    k: number of events, lambda_val: average rate of events.
    """
    if lambda_val <= 0 or k < 0:
        return "Error: Lambda must be positive and k must be non-negative."

    if cumulative:
        return stats.poisson.cdf(k, lambda_val)
    else:
        return stats.poisson.pmf(k, lambda_val)


# ==============================================================================
# 4. Continuous Probability Distributions
# ==============================================================================

def normal_dist_cdf(x, mu, sigma):
    """1. Normal Distr CDF: Calculates P(X <= x) for a Normal distribution."""
    if sigma <= 0:
        return "Error: Standard deviation must be positive."
    return stats.norm.cdf(x, loc=mu, scale=sigma)

def inverse_normal(p, mu=0, sigma=1):
    """
    2. Inverse Normal: Calculates the x-value (quantile) for a given cumulative probability p.
    If mu=0 and sigma=1, it calculates the Z-score.
    """
    if p < 0 or p > 1 or sigma <= 0:
        return "Error: Invalid parameters for Inverse Normal function."
    return stats.norm.ppf(p, loc=mu, scale=sigma)

def gamma_dist_cdf(x, alpha, beta, cumulative=True):
    """
    3. Gamma Dist CDF: Calculates P(X <= x) for a Gamma distribution.
    Uses the shape parameter (alpha) and rate parameter (1/beta).
    """
    if alpha <= 0 or beta <= 0:
        return "Error: Alpha and Beta must be positive."
    # scipy uses 'a' for shape (alpha) and 'scale' for 1/rate (beta)
    return stats.gamma.cdf(x, a=alpha, scale=beta)

def inverse_gamma(p, alpha, beta):
    """
    4. Inverse Gamma: Calculates the x-value (quantile) for a given cumulative probability p.
    Uses the shape parameter (alpha) and rate parameter (1/beta).
    """
    if p < 0 or p > 1 or alpha <= 0 or beta <= 0:
        return "Error: Invalid parameters for Inverse Gamma function."
    return stats.gamma.ppf(p, a=alpha, scale=beta)


# ==============================================================================
# 5. Inferential Statistics and Hypothesis Testing Tools
# ==============================================================================

def standard_error_of_mean(s_or_sigma, n):
    """1. Standard Error of Mean: Calculates SE = s / sqrt(n)."""
    if n <= 0:
        return "Error: Sample size n must be positive."
    return s_or_sigma / math.sqrt(n)

def z_critical_value(alpha, two_tailed=True):
    """2. Z-Critical Value: Finds the critical Z-score for a given significance level alpha."""
    if alpha <= 0 or alpha >= 1:
        return "Error: Alpha must be between 0 and 1."
    
    if two_tailed:
        # For a two-tailed test, we need the Z-score for 1 - alpha/2
        return stats.norm.ppf(1 - alpha / 2)
    else:
        # For a one-tailed test (upper tail), we need the Z-score for 1 - alpha
        return stats.norm.ppf(1 - alpha)

def t_critical_value(alpha, df, two_tailed=True):
    """3. T-Critical Value: Finds the critical T-score for a given significance level alpha and degrees of freedom df."""
    if alpha <= 0 or alpha >= 1 or df <= 0:
        return "Error: Invalid parameters for T-critical value."
    
    if two_tailed:
        # For a two-tailed test, use the T-score for 1 - alpha/2
        return stats.t.ppf(1 - alpha / 2, df)
    else:
        # For a one-tailed test (upper tail), use the T-score for 1 - alpha
        return stats.t.ppf(1 - alpha, df)

def f_critical_value(alpha, df1, df2):
    """
    4. F-Critical Value: Finds the critical F-score for a given significance level alpha and degrees of freedom df1 (numerator) and df2 (denominator).
    Assumes a one-tailed test for variance comparison (F-test for equality of variances).
    """
    if alpha <= 0 or alpha >= 1 or df1 <= 0 or df2 <= 0:
        return "Error: Invalid parameters for F-critical value."
    # stats.f.ppf finds the value corresponding to the given cumulative probability (1 - alpha)
    return stats.f.ppf(1 - alpha, dfn=df1, dfd=df2)

def z_test_statistic(x_bar, mu0, s_or_sigma, n):
    """
    5. Z-Test Statistic: Calculates the Z-test statistic for a single mean.
    x_bar: sample mean, mu0: hypothesized mean, s_or_sigma: population SD or sample SD, n: sample size.
    """
    se = standard_error_of_mean(s_or_sigma, n)
    if isinstance(se, str): # Handle error from SE function
        return se
    
    z = (x_bar - mu0) / se
    return z

def sample_size_mean(E, sigma, z_alpha_2):
    """
    6. Sample Size Formulas: Calculates min sample size (n) for a mean CI.
    E: Margin of Error, sigma: Population SD, z_alpha_2: Z-critical value for CI.
    """
    if E <= 0 or sigma <= 0 or z_alpha_2 <= 0:
        return "Error: E, sigma, and Z-critical value must be positive."
    
    n_float = ((z_alpha_2 * sigma) / E) ** 2
    # Always round up to ensure the margin of error is met
    return math.ceil(n_float)

def sample_size_proportion(E, p_hat, z_alpha_2):
    """
    6. Sample Size Formulas: Calculates min sample size (n) for a proportion CI.
    E: Margin of Error, p_hat: Estimated proportion (or 0.5 for conservative), z_alpha_2: Z-critical value for CI.
    """
    if E <= 0 or p_hat <= 0 or p_hat >= 1 or z_alpha_2 <= 0:
        return "Error: Invalid parameters for proportion sample size calculation."
    
    n_float = ((z_alpha_2 / E) ** 2) * p_hat * (1 - p_hat)
    # Always round up
    return math.ceil(n_float)

# ==============================================================================
# MENU INTERFACE FUNCTIONS
# ==============================================================================

def get_data_list():
    """Helper to safely get a list of numbers from user input."""
    while True:
        try:
            data_input = input("Enter data points separated by spaces (e.g., 1.5 2.0 3.5): ")
            data_list = [float(x) for x in data_input.split()]
            if not data_list:
                 print("Please enter at least one number.")
                 continue
            return data_list
        except ValueError:
            print("Invalid input. Please ensure all inputs are numbers.")

def get_float_input(prompt):
    """Helper to safely get a single float from user input."""
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a valid number.")

def get_int_input(prompt):
    """Helper to safely get a single integer from user input."""
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

def run_descriptive_stats(choice):
    """Runs the chosen Descriptive Statistics calculation."""
    data = get_data_list()
    
    if choice == 1:
        print(f"Result: Mean = {calculate_mean(data):.4f}")
    elif choice == 2:
        is_sample = input("Is this a sample? (y/n, default is y): ").lower() != 'n'
        result = calculate_variance(data, sample=is_sample)
        print(f"Result: Variance = {result:.4f}")
    elif choice == 3:
        is_sample = input("Is this a sample? (y/n, default is y): ").lower() != 'n'
        result = calculate_std_dev(data, sample=is_sample)
        print(f"Result: Standard Deviation = {result:.4f}")
    elif choice == 4:
        q1, med, q3 = calculate_median_quartiles(data)
        print(f"Result: Q1 = {q1:.4f}, Median (Q2) = {med:.4f}, Q3 = {q3:.4f}")
    elif choice == 5:
        min_val, q1, med, q3, max_val = calculate_five_number_summary(data)
        print(f"Result: Five Number Summary (Min, Q1, Median, Q3, Max) = ({min_val:.4f}, {q1:.4f}, {med:.4f}, {q3:.4f}, {max_val:.4f})")
    elif choice == 6:
        data_range, iqr = calculate_range_iqr(data)
        print(f"Result: Range = {data_range:.4f}, IQR = {iqr:.4f}")
    else:
        print("Invalid choice.")


def run_probability_tools(choice):
    """Runs the chosen Probability Tools calculation."""
    if choice == 1:
        n = get_int_input("Enter n (total items): ")
        k = get_int_input("Enter k (items to choose): ")
        result = calculate_combinations(n, k)
        print(f"Result: C({n}, {k}) = {result}")
    else:
        print("Invalid choice.")


def run_discrete_dist(choice):
    """Runs the chosen Discrete Probability Distribution calculation."""
    if choice == 1:
        p = get_float_input("Enter probability of success (p): ")
        result = geometric_mean(p)
        print(f"Result: Geometric Mean (E[X]) = {result:.4f}")
    elif choice == 2:
        n = get_int_input("Enter number of trials (n): ")
        k = get_int_input("Enter number of successes (k): ")
        p = get_float_input("Enter probability of success (p): ")
        is_cumulative = input("Calculate cumulative P(X<=k)? (y/n, default is n): ").lower() == 'y'
        result = binomial_probability(k, n, p, cumulative=is_cumulative)
        print(f"Result: P(X{'<=' if is_cumulative else '='}{k}) = {result:.6f}")
    elif choice == 3:
        k = get_int_input("Enter number of events (k): ")
        lambda_val = get_float_input("Enter average rate (lambda): ")
        is_cumulative = input("Calculate cumulative P(X<=k)? (y/n, default is n): ").lower() == 'y'
        result = poisson_probability(k, lambda_val, cumulative=is_cumulative)
        print(f"Result: P(X{'<=' if is_cumulative else '='}{k}) = {result:.6f}")
    else:
        print("Invalid choice.")


def run_continuous_dist(choice):
    """Runs the chosen Continuous Probability Distribution calculation."""
    if choice == 1:
        x = get_float_input("Enter x-value: ")
        mu = get_float_input("Enter mean (mu): ")
        sigma = get_float_input("Enter standard deviation (sigma): ")
        result = normal_dist_cdf(x, mu, sigma)
        print(f"Result: Normal CDF P(X<={x}) = {result:.6f}")
    elif choice == 2:
        p = get_float_input("Enter cumulative probability (p, e.g., 0.975): ")
        mu = get_float_input("Enter mean (mu, use 0 for Z-score): ")
        sigma = get_float_input("Enter standard deviation (sigma, use 1 for Z-score): ")
        result = inverse_normal(p, mu, sigma)
        print(f"Result: X-value/Z-score (PPF) = {result:.4f}")
    elif choice == 3:
        x = get_float_input("Enter x-value: ")
        alpha = get_float_input("Enter shape parameter (alpha): ")
        beta = get_float_input("Enter rate parameter (beta): ")
        result = gamma_dist_cdf(x, alpha, beta)
        print(f"Result: Gamma CDF P(X<={x}) = {result:.6f}")
    elif choice == 4:
        p = get_float_input("Enter cumulative probability (p): ")
        alpha = get_float_input("Enter shape parameter (alpha): ")
        beta = get_float_input("Enter rate parameter (beta): ")
        result = inverse_gamma(p, alpha, beta)
        print(f"Result: X-value (Quantile) = {result:.4f}")
    else:
        print("Invalid choice.")


def run_inferential_stats(choice):
    """Runs the chosen Inferential Statistics calculation."""
    if choice == 1:
        s_or_sigma = get_float_input("Enter SD (s or sigma): ")
        n = get_int_input("Enter sample size (n): ")
        result = standard_error_of_mean(s_or_sigma, n)
        print(f"Result: Standard Error of Mean = {result:.4f}")
    elif choice == 2:
        alpha = get_float_input("Enter significance level (alpha, e.g., 0.05): ")
        two_tailed = input("Is the test/CI two-tailed? (y/n, default is y): ").lower() != 'n'
        result = z_critical_value(alpha, two_tailed)
        print(f"Result: Z-Critical Value = {result:.4f}")
    elif choice == 3:
        alpha = get_float_input("Enter significance level (alpha, e.g., 0.05): ")
        df = get_int_input("Enter degrees of freedom (df): ")
        two_tailed = input("Is the test/CI two-tailed? (y/n, default is y): ").lower() != 'n'
        result = t_critical_value(alpha, df, two_tailed)
        print(f"Result: T-Critical Value = {result:.4f}")
    elif choice == 4:
        alpha = get_float_input("Enter significance level (alpha, e.g., 0.05): ")
        df1 = get_int_input("Enter df for numerator (df1): ")
        df2 = get_int_input("Enter df for denominator (df2): ")
        result = f_critical_value(alpha, df1, df2)
        print(f"Result: F-Critical Value = {result:.4f}")
    elif choice == 5:
        x_bar = get_float_input("Enter sample mean (x̄): ")
        mu0 = get_float_input("Enter hypothesized mean (μ₀): ")
        s_or_sigma = get_float_input("Enter SD (s or σ): ")
        n = get_int_input("Enter sample size (n): ")
        result = z_test_statistic(x_bar, mu0, s_or_sigma, n)
        print(f"Result: Z-Test Statistic = {result:.4f}")
    elif choice == 6:
        # Sample Size Sub-Menu
        print("\n--- Sample Size Formulas ---")
        print("1. Mean (CI)")
        print("2. Proportion (CI)")
        sub_choice = get_int_input("Choose sample size type: ")
        
        if sub_choice == 1:
            E = get_float_input("Enter Margin of Error (E): ")
            sigma = get_float_input("Enter Population SD (σ): ")
            z_alpha_2 = get_float_input("Enter Z-critical value (zα/2, e.g., 1.96): ")
            result = sample_size_mean(E, sigma, z_alpha_2)
            print(f"Result: Min Sample Size (n) = {result} (Always round up!)")
        elif sub_choice == 2:
            E = get_float_input("Enter Margin of Error (E): ")
            p_hat = get_float_input("Enter Estimated Proportion (p̂, use 0.5 for max sample size): ")
            z_alpha_2 = get_float_input("Enter Z-critical value (zα/2, e.g., 1.96): ")
            result = sample_size_proportion(E, p_hat, z_alpha_2)
            print(f"Result: Min Sample Size (n) = {result} (Always round up!)")
        else:
            print("Invalid sub-choice.")
    else:
        print("Invalid choice.")


def main_menu():
    """Main function to display the calculator menu and handle user input."""
    
    # Mapping the choices to their respective functions
    categories = {
        1: ("Descriptive Statistics", run_descriptive_stats, [
            "1. Mean", "2. Variance", "3. Sample Standard Deviation", 
            "4. Median and Quartiles", "5. Five Number Summary", 
            "6. Range and Interquartile Range (IQR)"
        ]),
        2: ("Probability Tools", run_probability_tools, [
            "1. Combinations C(n, k)"
        ]),
        3: ("Discrete Probability Distributions", run_discrete_dist, [
            "1. Geometric Mean (E[X])", "2. Binomial Probability P(X=k) or P(X<=k)", 
            "3. Poisson Probability P(X=k) or P(X<=k)"
        ]),
        4: ("Continuous Probability Distributions", run_continuous_dist, [
            "1. Normal Distribution CDF P(X<=x)", "2. Inverse Normal (Quantile/Z-score)", 
            "3. Gamma Distribution CDF P(X<=x)", "4. Inverse Gamma (Quantile)"
        ]),
        5: ("Inferential Statistics & Hypothesis Testing", run_inferential_stats, [
            "1. Standard Error of Mean", "2. Z-Critical Value (Inverse Normal)", 
            "3. T-Critical Value (Inverse T)", "4. F-Critical Value (Inverse F)", 
            "5. Z-Test Statistic (Single Mean)", "6. Sample Size Formulas"
        ])
    }
    
    while True:
        print("\n" + "="*50)
        print("Statistics Final Calculator Menu")
        print("="*50)
        
        for key, (name, _, _) in categories.items():
            print(f"{key}. {name}")
        
        print("0. Exit Calculator")
        
        main_choice = get_int_input("\nChoose a category (1-5) or 0 to exit: ")
        
        if main_choice == 0:
            print("Exiting Calculator. Good luck with your final!")
            break
        
        if main_choice in categories:
            category_name, runner, sub_menu = categories[main_choice]
            print("\n" + "-"*50)
            print(f"Category: {category_name}")
            print("-"*50)
            
            for item in sub_menu:
                print(item)
            
            sub_choice = get_int_input("\nChoose a function number: ")
            
            # The choice numbers (1, 2, 3...) match the index in the list, so we pass the sub_choice directly.
            runner(sub_choice)
            
            input("\nPress Enter to return to the main menu...")
            
        else:
            print("Invalid category choice. Please try again.")

if __name__ == '__main__':
    # Initialize error handling for the main menu system
    try:
        main_menu()
    except Exception as e:
        print(f"\nAn unexpected error occurred: {e}")
        print("Please restart the calculator.")

# Comment out the original example usage block if it was uncommented
# if __name__ == '__main__':
#     # Sample Data from Problem 23 (Fall 2021)
#     ...