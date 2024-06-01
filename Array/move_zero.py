#  Move Zero solutions

def move_zeros(nums:list)->list:
    count = 0
    for i,num in enumerate(nums):
        if num == 0:
            count +=1
            continue
        nums[i],nums[i-count] = nums[i-count],num[i]
    return num