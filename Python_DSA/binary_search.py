# python program to implement binary search on a list containing integers in descending order 
# function tested okay
# time complexity: O(log(n))
def locate_card(cards,query):
    low,high=0,len(cards)-1
    print('Searching......')
    while low <= high:
        mid = (low + high)//2
        print("low: ",low,", high: ",high,", mid: ",mid, ", mid_value: ",cards[mid],", query: ",query)
        loc_test= test_location(cards,query,mid)
        if loc_test == 'found':
            return mid
        elif loc_test == 'left':
            high = mid-1
        elif loc_test == 'right':
            low = mid+1
    
    return 'Not Found'

# test_location() is created to verify whether the first occurrence of a given query has been successfully located within a list that contains multiple occurrences of that query
# if query matched mid element then it would check if the element to the left of mid element is equal to query or not if it is then simply search space will shift to left
# function tested okay
def test_location(cards,query,mid):
    if cards[mid]==query:
        if (mid-1)>=0 and cards[mid-1]==query:
            return 'left'
        else:
            return 'found'
    elif query>cards[mid]:
        return 'left'
    else:
        return 'right' 


# test cases in the form of list of dictionaries
tests= [    {'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, 2, 1], 'query': 7}, 'output': 5}, #query in the middle of the list 
            {'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, 2, 1], 'query': 1}, 'output': 9},#query at the end of the list
            {'input': {'cards':[],'query':8},'output':'Not Found'}, # list is empty
            {'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, -1, -12], 'query': 13}, 'output': 0},# query at the start of the list
            {'input': {'cards': [13, 12, 11, 11, 11, 11, 10, 9, 7, 6, 5, -1, -12], 'query': 11}, 'output': 2},# list with multiple occurences of query 
            {'input': {'cards': [12, 12, 11, 11, 11, 10, 10, 9, 7, 6, 5, -1, -12], 'query': 9}, 'output': 7}, #list with some duplicate elements
            {'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, -1, -12], 'query': 14}, 'output': 'Not Found'},#query not in list
            {'input': {'cards': [12, 11, 11, 11, 11, 11, 11, 5, -1, -12], 'query': 11}, 'output': 1},# edge case when list has multiple occurences of query and query is also the middle element, for this case we created separate function test_location()
            {'input': {'cards': [13], 'query': 13}, 'output': 0} # list has only one element i.e query
        ]

# for test in tests:
#     print("card location: ",locate_card(**test['input']))

def evaluate_test_cases(function,tests):
    i = 1
    for test in tests:
        print('Test Case #',i,':')
        print('Input:',test['input']['cards'])
        print('Query:',test['input']['query'])
        expected_output = test['output']
        print('Expected Output:', expected_output)
        actual_output = function(**test['input'])
        print('Actual Output:',actual_output)
        if actual_output == expected_output:
            print('Test',i,'Passed\n')
        else:
            print('Test',i,'Failed\n')
        i+=1

evaluate_test_cases(locate_card,tests)
