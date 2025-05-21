# This python program multiplies two square matrices of same order

#initialize C = [[0,0,0,0,...],...]
def initialize_mat(dim):
    C = []  #create empty list 
    for i in range(dim):
        C.append([])            # append dim times empty lists in external list ==> we have : [[],[],[],[], .... upto dim times] 
    for i in range(dim):        # iterate over C
        for j in range(dim):    # iterate inside C[i]
            C[i].append(0)      # append dim times 0 in c[i] ===> we have : [[0,0,0,...dim times],......dim times]
    return C           

# print(initialize_mat(5))    

def dot_product(u,v):
    dim = len(u)
    ans = 0
    for i in range(dim):
        ans += u[i]*v[i]  
    return ans

# print(dot_product([1,2,3],[4,5,6]))

def row(M,i):
    row=[]
    dim =len(M)
    for j in range(dim):
        row.append(M[i][j])
    return row

def column(M,i):
    column = []
    dim = len(M)
    for j in range(dim):
        column.append(M[j][i])
    return column

    
def matrix_multiply(A,B):
    dim = len(A)
    C = initialize_mat(dim)
    for i in range(dim):
        for j in range(dim):
            C[i][j] = dot_product(row(A,i),column(B,j))
    return C        
    

A = [[1,1,1],[2,2,2]]
B = [[1,2],[1,2],[1,2]]

print(matrix_multiply(A,B))
# consider 3 matrices A, 3x4 B 4x5, C 5x3. Find the minimum no. of multiplications required to calculate D = ABC