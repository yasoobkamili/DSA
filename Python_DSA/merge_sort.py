def merge_sort(nums):
    if len(nums) <= 1:
        return nums
    
    mid = len(nums)//2
    left = nums[:mid]  # list slicing , this will start list from index 0 to mid - 1
    right = nums[mid:]
    print(left,right)
    left_sorted , right_sorted = merge_sort(left), merge_sort(right)

    sorted_nums = merge(left_sorted,right_sorted)
    
    return sorted_nums
    
def merge(nums1,nums2):
    merged = []
    i, j = 0, 0

    while i < len(nums1) and j < len(nums2):
        if nums1[i]<nums2[j]:
            merged.append(nums1[i])
            i+=1
        elif nums2[j]<nums1[i]:
            merged.append(nums2[j])
            j+=1
    
    return merged + nums1[i:] + nums2[j:]

num = [5,4,3,1,2,8,9,7]
print(num)
print(merge_sort(num))