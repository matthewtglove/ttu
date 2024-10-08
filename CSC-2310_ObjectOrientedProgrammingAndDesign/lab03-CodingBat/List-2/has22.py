def has22(nums):
    is2 = False
    for n in nums:
        if (n == 2):
            if (is2):
                return True

            is2 = True
            continue
        
        is2 = False
    
    return False