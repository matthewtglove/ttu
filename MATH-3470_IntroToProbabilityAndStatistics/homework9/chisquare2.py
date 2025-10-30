from scipy.stats import chi2

# Parameters
k = 13  # degrees of freedom
x = 18  # value to calculate CDF at

# Chi-square CDF
cdf_value = chi2.cdf(x, df=k)

print(f"CDF of chi-square({k}) at x={x}: {cdf_value:.4f}")

a = 6
b = 18
prob = chi2.cdf(b, df=k) - chi2.cdf(a, df=k)
print(f"P({a} < X < {b}) = {prob:.4f}")
