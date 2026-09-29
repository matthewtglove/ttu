# Recursive definition of the set W consisting of all odd length strings consisting of the elemnts of the set {a, b}.

# Basis: a, b belongs to R
R = ["a", "b"]

# Recursive step: If t belongs to R, then...
# taa belongs to R
# tab belongs to R
# tba belongs to R
# tbb belongs to R

# Closure: No one else.

t = None
a = "a"
b = "b"

for i in range(0, 100):
    t = R[i]

    R.append(t + a + a)
    R.append(t + a + b)
    R.append(t + b + a)
    R.append(t + b + b)

print(R)