def count_hi(str):
    hiCount = 0
    isH = False
    for x in str:
        if (x == "h"):
            isH = True
            continue
        if (x == "i" and isH):
            hiCount = hiCount + 1

    return hiCount


# --- Better solution ---

def count_hi(str):
    sum = 0
    ## Loop to length-1 and access index i and i+1
    ## in the loop.
    for i in range(len(str)-1):
        if str[i:i+2] == 'hi':
            sum = sum + 1
    return sum
