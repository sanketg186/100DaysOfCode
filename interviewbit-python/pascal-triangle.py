# Pascal Triangle
# Given numRows, generate the first numRows of Pascal’s triangle.

# Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

class Solution:
    # @param A : integer
    # @return a list of list of integers
    def find_bin_coef(self,n):
        res = 1
        v = []
        v.append(res)
        for i in range(1,n+1):
            res = int(res*(n-i+1)/i)
            v.append(res)
        return v

    def solve(self, A):
        res = []
        for i in range(0,A):
            v = self.find_bin_coef(i)
            res.append(v)

            
        return res
