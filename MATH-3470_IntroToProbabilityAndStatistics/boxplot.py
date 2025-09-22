import matplotlib.pyplot as plt
import numpy as np

data = [60, 60, 61, 61, 61, 61, 62, 62, 64, 64, 64, 65, 67, 69, 70, 71, 72, 73, 75, 76, 77, 83, 86, 89, 92, 99, 99, 100]


# Five Number Summary
low = min(data)
q1 = np.percentile(data, 25)
q2 = np.percentile(data, 50)
q3 = np.percentile(data, 75)
high = max(data)

print("Five Number Summary:")
print("Low:", low)
print("Q1:", q1)
print("Q2:", q2)
print("Q3:", q3)
print("High:", high)

# Create boxplot
plt.boxplot(data, vert=False, patch_artist=True)
plt.title("Boxplot")
plt.xlabel("Values")
plt.grid(axis='x')
plt.show()