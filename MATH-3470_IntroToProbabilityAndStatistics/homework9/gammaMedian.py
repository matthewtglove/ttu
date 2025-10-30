from scipy.stats import gamma

alpha = 10      # shape
rate = 6.5      # rate λ
scale = 1 / rate  # scale θ = 1/λ

median = gamma.median(a=alpha, scale=scale)
print("Median:", median)
