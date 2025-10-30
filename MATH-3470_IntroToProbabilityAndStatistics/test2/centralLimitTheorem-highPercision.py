from mpmath import mp, mpf, erf

# Set precision (number of decimal places)
mp.dps = 50  

# Parameters
mu = mpf(100)
sigma = mpf(15)
n = 49
x_bar = mpf(120)

# Standard error
sigma_xbar = sigma / mp.sqrt(n)

# Z-score
z = (x_bar - mu) / sigma_xbar

# Normal CDF using error function
cdf = (1 + erf(z / mp.sqrt(2))) / 2
p = 1 - cdf

print(f"P(average IQ > {x_bar}) = {p}")
