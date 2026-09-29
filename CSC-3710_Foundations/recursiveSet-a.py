# Recusrive definition of the set S of all strings consisting of the elements of the set {a, b}, that contain an odd number of a's

# What this would look like: S = {a, ab, ba, aaa, abb, bab, bba, aaab, aaba, ...}

# Basis: a belongs to P
P = ["a"]

# Recursive step: If t belongs to P, then...
# taa belongs to P
# tb belongs to P
# bt belongs to P
# ata belongs to P

# Closure: No one else.

t = None
a = "a"
b = "b"

for i in range(0, 50):
    t = P[i]

    P.append(t + a + a)
    P.append(t + b)
    P.append(b + t)
    P.append(a + t + a)

P = sorted(P, key=len)
print(P)