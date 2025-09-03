import matplotlib.pyplot as plt
import numpy as np

x = [26, 27, 30, 28, 34, 22, 19, 31, 22, 25, 24, 18, 17, 19, 28, 15, 37, 32, 28, 40]
y = [58, 57, 61, 60, 70, 46, 49, 39, 44, 56, 48, 47, 41, 48, 48, 27, 68, 65, 55, 76]


plt.plot(x, y, marker='o', linestyle='None')
plt.title("Scatterplot")
plt.xlabel("X-axis")
plt.ylabel("Y-axis")

# trendline
z = np.polyfit(x, y, 1)
p = np.poly1d(z)
plt.plot(x, p(x), linestyle='-', color='red')

plt.show()