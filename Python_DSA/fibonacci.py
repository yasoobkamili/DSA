# recurcive approach 
# Time Complexity: O(2^n) i.e Exponential growth
# T(n) = fibonacci(n)-1
def fibonacci(num):
    if num<=1:
        return num
    else:
        return fibonacci(num-2) + fibonacci(num-1)
    
fib_list = []   # list to store series
for i in range(8):
    fib_list.append(fibonacci(i))
print(fib_list)


# efficient approach
# Time Complexity: O(n) i.e linear growth

def better_fibonacci(num):
    if num<=1:#(num ==1 or num == 0):
        return num
    else:
        a, b = 0,1
        for i in range (1,num):
            temp = a+b
            a,b=b,temp
        return b
l2 = []   # list to store series
for i in range(8):
    l2.append(better_fibonacci(i))
print(l2)
