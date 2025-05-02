#bubble sort algorithm
#time complexity: O(n^2)

import random
test = list(range(1000000))
random.shuffle(test)
out_list = list(range(1000000))
print(test == out_list)
# nums1 = [2,3,1,6,4,7,5,9,8]
nums1 = [2,3,1,5,6,4,5,7,5,9,8]
nums2 = [1,2,3,4,5,6,7,8,9]
def bubble_sort(nums):
    for j in range(len(nums)-1):
        for i in range(len(nums)-1-j):
            if nums[i] > nums[i+1]:
                nums[i],nums[i+1]= nums[i+1],nums[i]
    return nums

print(bubble_sort(nums1))
print(bubble_sort(nums2))
# print(bubble_sort(test))
print(out_list == bubble_sort(test))