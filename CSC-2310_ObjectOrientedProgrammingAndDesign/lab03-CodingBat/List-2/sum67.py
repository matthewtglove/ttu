def sum67(nums):
    if (len(nums) < 0):
        return 0
    
    cleanSum = 0
    infected = False
    for n in nums:
        if (n == 6):
            infected = True
            continue

        if (n == 7 and infected):
            infected = False
            continue
        
        if (infected):
            continue

        cleanSum = cleanSum + n

    return cleanSum