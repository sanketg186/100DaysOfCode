# Maximum Absolute Difference
# You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) 
# for all 1 ≤ i, j ≤ N.
# f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

# For example,

# A=[1, 3, -1]

class Solution:
    # @param A : list of integers
    # @return an integer
    def maxArr(self, A):
        a = []
        b = []
        n = len(A)
        for i in range(0,n):
            a.append(A[i]+i)
            b.append(A[i]-i)
        
        a.sort(reverse=True)
        b.sort(reverse=True)
        max_sum = max(a[0]-a[-1],b[0]-b[-1])
        return max_sum

