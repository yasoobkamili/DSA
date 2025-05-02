# determine minimum no. of times the given rotated sorted list was rotated, assume list contains unique elements only 
# here rotation refers to right rotation by 1
l1 = [6,7,8,0,1,2,3,4,5] # rotated 3 times
l2 = [7,9,3,5,6] # rotated 2 times
l3 = [2,3,4,5,6,7,1] # rotated 6 times
l4 = [-1,2,3,4,5,6,7,8,9,10] # rotated 0 times
l5 = [] # empty list cannot be rotated
tests = []
tests.append(l1)
tests.append(l2)
tests.append(l3)
tests.append(l4)
tests.append(l5)

# brute force approach 
# smallest number of the list is at the kth index where k is no of rotations  
# Time Complexity: O(n)
def count_rotations_linear(nums):
    if not nums: #this checks if the there is nothing in nums list
        return 'empty list cannot be rotated'
    for i in range(0,len(nums)-1):
        if i>0 and nums[i]>nums[i+1]:
            return i+1
       
    return 0
    
    # pivot = nums[len(nums)-1]   # or we can use nums[-1] to point to last element
    # count = 0       # to keep count of elements before smallest elememt of the list
    # for num in nums:
    #     if num > pivot:
    #         count+=1
    #     else:
    #         return count
  
print('count rotations linear called')
for nums in tests:
    print('min rotation count:',count_rotations_linear(nums),'\t', nums)

# minimum rotation count using binary search method
# time complexity: O(log(n))
def count_rotations_binary(nums):
    if not nums:
        return 'list khali hai'
    pivot = nums[-1]
    low,high = 0 , len(nums)-1
    while low<=high:
        mid = (low+high)//2
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

print('\ncount roations binary called ')
for nums in tests:
    print('min rotation count:',count_rotations_binary(nums),'\t', nums)



# build a funtion to test all the test cases for a function
# signature fn: def eval_test_cases(function, tests): pass
# maybe tests = [] will have a fixed format
# tests =[{{'input':[6,7,1,2,3,4,5], 'query': 6},'output':3}]

tests =[{'input':[6,7,1,2,3,4,5], 'query': 6,'output':2},{'input':[6,7,8,0,1,2,3,4,5], 'query': 6,'output':3}]

def evaluate_test_cases(function,tests):
    i = 1
    for test in tests:
        print('Test Case #',i,':')
        print('Input:',test[i]['input'])
        # print('Query:',test['input']['query'])
        expected_output = test[i]['output']
        print('Expected Output:', expected_output)
        actual_output = function(**test[i]['input'])
        print('Actual Output:',actual_output)
        if actual_output == expected_output:
            print('Test',i,'Passed\n')
        else:
            print('Test',i,'Failed\n')
        i+=1

# evaluate_test_cases(count_rotations_linear,tests) 
