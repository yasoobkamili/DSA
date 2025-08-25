# we have a max capacity of knapsack called 'M'
# we have 'N' no. of objects
# we have total profit called 'P'
# time complexity : O(nlog(n))

def knapsack(weights,profits,M):
    items = []
    for i in range(len(weights)):
        items.append((profits[i]/weights[i],profits[i],weights[i]))
    items.sort(reverse=True)

    P=0
    for i in range(len(items)):
        pwRatio,p,w = items[i]
        if M>0 and w<M:
            M -= w
            P += p
        elif M>0:
            P = P + M*pwRatio 
            break
    return P

profits = [10,5,15,7,6,18,3]
weights = [2,3,5,7,1,4,1]
M = 15
print(knapsack(weights,profits,M))