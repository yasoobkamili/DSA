#brute force approach for finding an element in a sorted list
# time complexity : O(n)
#space complexity : O(1) 
def locate_card(cards,query):
    position = 0
    print("cards: ",cards)
    print("query: ",query)
    print("position: ",position)
    while position<len(cards):
        if cards[position] == query:
            return position
        position +=1
    return -1
       
cards = [13,12,11,10,8,6,4,3,2,1]
query = 0
tests= [{'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, 2, 1], 'query': 7}, 'output': 5}, 
        {'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, 2, 1], 'query': 1}, 'output': 9},
        {'input':{'cards':[],'query':8},'output':-1},
        {'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, -1, -12], 'query': 13}, 'output': 0},
        {'input': {'cards': [13, 12, 11, 11, 11, 11, 10, 9, 7, 6, 5, -1, -12], 'query': 11}, 'output': 2},
        {'input': {'cards': [12, 12, 11, 11, 11, 10, 10, 9, 7, 6, 5, -1, -12], 'query': 9}, 'output': 7}, 
        {'input': {'cards': [13, 12, 11, 10, 9, 7, 6, 5, -1, -12], 'query': 14}, 'output': -1},
        {'input': {'cards': [13], 'query': 13}, 'output': 0}]

for test in tests:
    print("card location: ",locate_card(**test['input']))
    