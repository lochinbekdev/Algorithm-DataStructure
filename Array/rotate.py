#Rotate numbers function

def rotate(nums:list,k:int):
    k = k % len(nums)
    print(len(nums))
    return nums[-k:] + nums[:-k]

numbers=[1,2,3,4]

result=rotate(numbers,6)

print(result)