# 3x3 matrix
A = [[10,20,30],
    [40 ,50,60],
    [70 ,80,90]]

# 3x3 matrix
B = [[5,8,1],
    [6,7,3],
    [4,9,1]]

# result is 3x3
result = [[0,0,0],
         [0,0,0],
         [0,0,0]]

# iterate through rows of A
for i in range(len(A)):

   # iterate through columns of B
   for j in range(len(B)):

       # iterate through rows of B
       for k in range(len(B)):
           result[i][j] += A[i][k] * B[k][j]

for r in result:
   print(r)


