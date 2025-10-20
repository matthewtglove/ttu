# Creating plots and numeric computations for the user's request.
# This code will:
# 1) compute numerical probabilities for Uniform(0,1) and Exponential(mean=2.5)
# 2) plot pdf and cdf on the same axes for Uniform(0,1)
# 3) plot pdf and cdf on the same axes for Exponential(lambda=0.4)
# Notes: using matplotlib (no seaborn). No explicit color/style specifications are set.

import numpy as np
import matplotlib.pyplot as plt

# Parameters
a, b = 0.0, 1.0
lam = 1/2.5  # lambda = 0.4

# x ranges
x_u = np.linspace(-0.2, 1.2, 500)
x_e = np.linspace(-0.2, 10, 1000)

# Uniform pdf and cdf
f_u = np.where((x_u >= a) & (x_u <= b), 1/(b-a), 0.0)
F_u = np.where(x_u < a, 0.0, np.where(x_u > b, 1.0, (x_u - a)/(b-a)))

# Exponential pdf and cdf
f_e = np.where(x_e >= 0, lam * np.exp(-lam * x_e), 0.0)
F_e = np.where(x_e < 0, 0.0, 1 - np.exp(-lam * x_e))

# Numeric probabilities
# Uniform(0,1)
p_u_eq_015 = 0.0  # continuous distribution
p_u_lt_077 = 0.77
p_u_gt_028 = 1 - 0.28
p_u_between = max(0.0, min(0.37, 1.0) - max(-0.15, 0.0))  # (-0.15,0.37) intersect [0,1]

# Exponential(lambda=0.4)
p_e_eq_015 = 0.0
p_e_lt_077 = 1 - np.exp(-lam * 0.77)
p_e_gt_028 = np.exp(-lam * 0.28)
# (-0.15,0.37) intersect [0,inf) => (0,0.37)
p_e_between = 1 - np.exp(-lam * 0.37)

# Print computed numeric probabilities with 6 decimal precision
print("=== Numeric probabilities ===")
print("Uniform(0,1):")
print(f"P(X = 0.15) = {p_u_eq_015:.6f}")
print(f"P(X < 0.77) = {p_u_lt_077:.6f}")
print(f"P(X > 0.28) = {p_u_gt_028:.6f}")
print(f"P(-0.15 < X < 0.37) = {p_u_between:.6f}")
print()
print("Exponential(mean=2.5 -> lambda=0.4):")
print(f"P(X = 0.15) = {p_e_eq_015:.6f}")
print(f"P(X < 0.77) = {p_e_lt_077:.6f}")
print(f"P(X > 0.28) = {p_e_gt_028:.6f}")
print(f"P(-0.15 < X < 0.37) = {p_e_between:.6f}")

# Plot for Uniform
fig, ax = plt.subplots(figsize=(8,4))
ax.plot(x_u, f_u, label='pdf (f(x))')
ax.plot(x_u, F_u, label='cdf (F(x))')
ax.set_xlabel('x')
ax.set_title('Uniform(a=0, b=1): pdf and cdf on same axes')
ax.set_ylim(-0.1, 1.2)
ax.set_xlim(-0.2, 1.2)
ax.grid(True, linewidth=0.3)

# mark important points
ax.axvline(0, linestyle='--', linewidth=0.7)
ax.axvline(1, linestyle='--', linewidth=0.7)
ax.scatter([0,1],[1.0,1.0], s=30)  # pdf value at [0,1] is 1 for uniform
ax.scatter([0,1],[0.0,1.0], s=30)  # cdf values: F(0)=0, F(1)=1
ax.annotate('pdf height = 1', xy=(0.5,1.0), xytext=(0.55,1.05))
ax.annotate('F(0)=0', xy=(0,0.0), xytext=(0.05,-0.08))
ax.annotate('F(1)=1', xy=(1,1.0), xytext=(0.6,0.92))

ax.legend()

plt.show()

# Plot for Exponential
fig, ax = plt.subplots(figsize=(8,4))
ax.plot(x_e, f_e, label='pdf (f(x))')
ax.plot(x_e, F_e, label='cdf (F(x))')
ax.set_xlabel('x')
ax.set_title('Exponential(lambda=0.4): pdf and cdf on same axes')
ax.set_ylim(-0.05, 1.05)
ax.set_xlim(-0.2, 10)
ax.grid(True, linewidth=0.3)

# mark important points: mean, median (optional), pdf at 0, cdf at 0
mean = 1/lam
ax.scatter([0, mean], [lam, 0.0], s=30)  # pdf at 0 is lambda, cdf at mean ~ 1-e^{-1}
ax.annotate(f'pdf(0)=λ = {lam:.2f}', xy=(0, lam), xytext=(0.5, lam+0.05))
ax.annotate(f'mean = 1/λ = {mean:.2f}', xy=(mean, 0), xytext=(mean+0.5, 0.05))
ax.annotate(f'F(mean)=1-e^{{-1}}≈{1-np.exp(-1):.3f}', xy=(mean, 1-np.exp(-1)), xytext=(mean+0.5, 0.5))

ax.legend()
plt.show()
