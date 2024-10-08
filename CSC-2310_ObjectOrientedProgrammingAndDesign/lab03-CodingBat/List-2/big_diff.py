def big_diff(nums):
    if (len(nums) < 1):
        return -1

    min = nums[0]
    max = nums[0]
    for x in nums:
        if (x < min):
            min = x
            continue
        
        if (x > max):
            max = x

    return max - min