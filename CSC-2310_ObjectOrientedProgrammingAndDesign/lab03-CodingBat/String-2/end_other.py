def end_other(a, b):
    shortestLength = min(len(a), len(b))
    if(len(a) > len(b)):
        return (a[-shortestLength:].lower() == b.lower())

    return (b[-shortestLength:].lower() == a.lower())

# Better solution with endswith()
def end_other(a, b):
    a = a.lower()
    b = b.lower()
    return (b.endswith(a) or a.endswith(b))