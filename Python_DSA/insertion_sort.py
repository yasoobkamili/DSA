def insertion_sort(nums):
    nums = list(nums)
    for i in range(len(nums)):
        cur = nums.pop(i)
        j = i-1
        while j>=0 and nums[j]>cur:
            j-=1
        nums.insert(j+1,cur)
    return nums

print(insertion_sort([6,2,7,1,9,3,8,5,4]))
