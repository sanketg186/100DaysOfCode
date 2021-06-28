# Anti Diagonals
# Input: 	

# 1 2 3
# 4 5 6
# 7 8 9

# Return the following :

# [ 
#   [1],
#   [2, 4],
#   [3, 5, 7],
#   [6, 8],
#   [9]
# ]

class Solution:
    # @param A : list of list of integers
    # @return a list of list of integers
    def diagonal(self, A):
        r = len(A)
        c = len(A[0])
        res =  [[] for i in range(0,r+c-1)]
        for i in range(0,r):
            for j in range(0,c):
                res[i+j].append(A[i][j])
        
        return res
