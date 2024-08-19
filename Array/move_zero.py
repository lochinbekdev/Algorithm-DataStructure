#  Move Zero solutions

def move_zeros(nums): 
    count = 0
    for i,num in enumerate(nums):
        if num == 0:
            count +=1
            continue
        nums[i],nums[i-count] = nums[i-count],nums[i]
    return nums

