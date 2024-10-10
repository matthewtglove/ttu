def end_other(a, b):
    shortestLength = min(len(a), len(b))
    return (a[-shortestLength-1:].lower == b[-shortestLength-1:].lower)