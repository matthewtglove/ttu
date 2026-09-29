# Recursive definition of the set V consisting of all even length strings consisting of the elemnts of the set {a, b}.

# Basis: "" belongs to K
K = [""]

# Recursive step: If t belongs to K, then...
# taa belongs to K
# tab belongs to K
# tba belongs to K
# tbb belongs to K

# Closure: No one else.

t = None
a = "a"
b = "b"

for i in range(0, 100):
    t = K[i]

    K.append(t + a + a)
    K.append(t + a + b)
    K.append(t + b + a)
    K.append(t + b + b)

print(K)