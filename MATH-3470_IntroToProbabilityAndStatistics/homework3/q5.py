import math
from fractions import Fraction

# 4. In a box are 7 red balls and 8 blue balls. From this box are drawn 3 balls and placed in a second box.  Then, one ball is drawn from the second box. What is the probability the ball drawn from the second box is red?
#
# P(Drawing red) = 7/15. There separate events don't change the red-to-blue ratio.
#
# 5. Using the same scenario as in the problem above, if we are given the ball drawn from the second box is red, what is the probability that 2 red balls and 1 blue ball were transferred from box 1 to box 2?
#
# Using Bayes Rule.
#
# A: 2 red, 1 blue in box 2
# B: ball drawn from box 2 is red
#
# We need to find P(A | B)
#
# P(A | B)   =   P(B and A) / P(B)   =   P(B | A)P(A) / P(B)
# P(A | B)   =   P(B|A)P(A) / ( P(B|A)P(A) + P(B|AC)P(AC)


pA = Fraction(math.comb(7, 2) * math.comb(8, 1), math.comb(15, 3))
print("P(A) =", pA)

pB = Fraction(7 / 15)
print("P(B) =", pB)
