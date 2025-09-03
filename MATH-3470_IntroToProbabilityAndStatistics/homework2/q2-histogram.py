import matplotlib.pyplot as plt

x = [31, 39, 47, 25, 35, 43, 37, 38, 53, 51, 46, 48, 41, 55, 59, 38, 56, 42, 34, 31, 38, 50, 43, 41, 34, 44, 46, 22, 49, 47, 22, 27, 35, 34, 44, 43, 44, 21, 42, 31, 43, 44]

plt.hist(x, rwidth=0.8)
plt.title('Histogram')
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.show()