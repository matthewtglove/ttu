def centered_average(nums):
    min = nums[0]
    max = nums[0]
    for x in nums:
        if (x < min):
            min = x
            continue
        
        if (x > max):
            max = x

    entireSum = 0
    for n in nums:
        entireSum = entireSum + n
    
    centeredSum = entireSum - min - max
    centeredLength = len(nums) - 2
    return centeredSum / centeredLength