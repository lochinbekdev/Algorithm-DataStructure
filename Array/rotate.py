#Rotate numbers function

def rotate(nums:list,k:int):
    k = k % len(nums)
    return nums[-k:] + nums[:-k]
