def sum13(nums):
    if (len(nums) < 0):
        return 0
    
    cleanSum = 0
    infected = False
    for n in nums:
        if (n == 13):
            infected = True
            continue
        
        if (infected):
            infected = False
            continue

        cleanSum = cleanSum + n

    return cleanSum