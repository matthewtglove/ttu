import numpy as np
from math import comb  # for binomial coefficients

# Given values
n = 12
p = 0.20

# Complement rule: P(Y >= 2) = 1 - P(Y <= 1)
# Calculate P(Y=0)
P0 = comb(n, 0) * (p**0) * ((1-p)**n)

# Calculate P(Y=1)
P1 = comb(n, 1) * (p**1) * ((1-p)**(n-1))

# P(Y >= 2)
P_at_least_2 = 1 - (P0 + P1)

print("Probability that at least 2 are unmarried:", P_at_least_2)

# --- Exactly 2 ---

# Given values
n = 12      # total women
p = 0.20    # probability of unmarried
y = 2       # exactly 2 unmarried

# Binomial probability formula
P_exactly_2 = comb(n, y) * (p**y) * ((1-p)**(n-y))

print("Probability that exactly 2 are unmarried:", P_exactly_2)

# --- Graphing different exact values ---

import matplotlib.pyplot as plt

# Given values
n = 12
p = 0.20

# Calculate probabilities for Y = 0, 1, ..., 12
y_values = list(range(n+1))
probabilities = [comb(n, y) * (p**y) * ((1-p)**(n-y)) for y in y_values]

# Plot
plt.bar(y_values, probabilities, color='skyblue')
plt.xlabel('Number of unmarried women (Y)')
plt.ylabel('Probability P(Y=y)')
plt.title('Binomial Probabilities: n=12, p=0.2')
plt.xticks(y_values)
plt.show()
