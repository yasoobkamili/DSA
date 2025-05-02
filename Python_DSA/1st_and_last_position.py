# Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
# If target is not found in the array, return [-1, -1].
# Leetcode 
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        return first_and_last(nums,target)
    
def binary_search(low, high,condition):
    while low<=high:
        mid = (low+high)//2
        result = condition(mid)
        if result == 'found':
            return mid
        elif result == 'left':
            high = mid - 1
        else:
            low = mid+1
    return -1        
    
def first_pos_test(nums,target):
    def condition(mid):
        if nums[mid] == target:
            if mid>=0 and nums[mid-1]==target:
                return 'left'
            else:
                return 'found'
        elif nums[mid] > target:
            return 'left'
        else:
            return 'right'
    return binary_search(0,(len(nums)-1),condition)

def last_pos_test(nums,target):
    def condition(mid):
        if nums[mid] == target:
            if mid<len(nums) and nums[mid+1]==target:
                return 'right'
            else:
                return 'found'
        elif nums[mid] > target:
            return 'left'
        else:
            return 'right'
    return binary_search(0,len(nums)-1,condition)

def first_and_last(nums,target):
    return first_pos_test(nums,target), last_pos_test(nums,target)

s1 = Solution()
print(s1.searchRange([1,2,3,5,5,5,5,6,7,8],5))
