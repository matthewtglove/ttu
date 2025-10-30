from scipy.stats import norm

# Given parameters
mu = 100          # population mean
sigma = 15        # population standard deviation
n = 49            # sample size
x_bar = 120       # sample mean to check

# Standard error of the mean
sigma_xbar = sigma / (n ** 0.5)

# Z-score for the sample mean
z = (x_bar - mu) / sigma_xbar

# Probability that sample mean is greater than x_bar
p = 1 - norm.cdf(z)

print(f"Z-score: {z:.2f}")
print(f"P(average IQ > {x_bar}) = {p:.10f}")
