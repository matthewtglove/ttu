import math

# 5 choose 2
# print(math.comb(5, 0))

Y0 = 1 * (1/6)**0 * (5/6)**5
Y1 = 5 * (1/6)**1 * (5/6)**4
Y2 = 10 * (1/6)**2 * (5/6)**3
Y3 = 10 * (1/6)**3 * (5/6)**2
Y4 = 5 * (1/6)**4 * (5/6)**1
Y5 = 1 * (1/6)**5 * (5/6)**0

# print each value on new lines
print(Y0)
print(Y1)
print(Y2)
print(Y3)
print(Y4)
print(Y5)

zeroDollarOdds = Y0 + Y1 + Y2
oneDollarOdds = Y3
twoDollarOdds = Y4 + Y5

print("Odds of $0:", zeroDollarOdds)
print("Odds of $1:", oneDollarOdds)
print("Odds of $2:", twoDollarOdds)

payout = (0 * zeroDollarOdds) + (1 * oneDollarOdds) + (2 * twoDollarOdds)
print("Expected payout:", payout)