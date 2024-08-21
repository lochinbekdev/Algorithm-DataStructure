def buble_sort(array:list)->list:
    for i in range(len(array)):
        for j in range(len(array)-i-1):
            if array[j] > array[j+1]:
                print(array[j],array[j+1])
                array[j],array[j+1] = array[j+1],array[j]
                
    return array

array=[5,2,3,6,4,7,1,8]
result=buble_sort(array)
print(result)