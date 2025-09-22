import numpy as np
from math import comb  # for binomial coefficients

# --- Graphing different exact values ---

import matplotlib.pyplot as plt

# Given values
n = 25
p = 0.80

# Calculate probabilities for Y = 0, 1, ..., 12
y_values = list(range(n+1))
probabilities = [comb(n, y) * (p**y) * ((1-p)**(n-y)) for y in y_values]

# --- At least 22 ---
P_at_least_22 = sum(probabilities[22:])
print("Probability that at least 22 are wrong:", P_at_least_22)

# Plot
plt.bar(y_values, probabilities, color='skyblue')
plt.xlabel('Number of wrong (Y)')
plt.ylabel('Probability P(Y=y)')
plt.title('Binomial Probabilities: n=25, p=0.8')
plt.xticks(y_values)
plt.show()