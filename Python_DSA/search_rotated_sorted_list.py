def search( nums, target):
    lo = count_rotations_binary(nums)
    print("lo is:",lo)
    if target >= nums[lo] and target<=nums[-1]:
        print("last element:",nums[-1])
        print('1st')
        print("position is",binary_search(nums,lo,len(nums)-1,target))
    else:
        print('2nd')
        print("position is",binary_search(nums,0,lo-1,target))

def count_rotations_binary(nums):
    if not nums:
        return -1
    pivot = nums[-1]
    print("pivot:",pivot)
    low,high = 0 , len(nums)-1
    while low<high:
        mid = (low+high)//2
        print('mid:',mid)
        if nums[mid]>pivot:
            if nums[mid] >nums[mid+1]:
                return mid+1
            else:
                low = mid +1
        if nums[mid]<pivot:
            if nums[mid]<nums[mid-1]:
                return mid
            else: 
                high = mid -1
    return 0
def binary_search(nums,low,high,target):
    while low<=high:
        mid = (low+high)//2
        if  nums[mid] == target:
            return mid
        elif target<nums[mid]:
            high = mid-1
        else:
            low = mid+1
    return -1

search([7],0)
search([6,7,8,1,2,3,4,5],0)
search([4,5,6,7,0,1,2],0)