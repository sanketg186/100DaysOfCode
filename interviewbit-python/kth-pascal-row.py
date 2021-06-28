# Kth Row of Pascal's Triangle
# Given an index k, return the kth row of the Pascal’s triangle.

# Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

# Example:

# Input : k = 3

# Return : [1,3,3,1]

#     NOTE : k is 0 based. k = 0, corresponds to the row [1].

# Note:Could you optimize your algorithm to use only O(k) extra space?


class Solution:
    # @param A : integer
    # @return a list of integers
    def getRow(self, A):
        n = A+1
        dp = [[0]*n for i in range(0,n)]
        # print(dp)
        for i in range(0,n):
            dp[i][0] = 1
            dp[i][i] = 1
        
        # print(dp)
        for i in range(2,n):
            for j in range(1,i):
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
        
        # print(dp)
        return dp[n-1]