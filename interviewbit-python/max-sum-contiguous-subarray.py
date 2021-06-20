# Max Sum Contiguous Subarray
# Find the contiguous subarray within an array, A of length N which has the largest sum.
# Input Format:
# The first and the only argument contains an integer array, A.
# Output Format:
# Return an integer representing the maximum possible sum of the contiguous subarray.



class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maxSubArray(self, A):
        n = len(A);
        curr_sum = 0
        max_sum = -1000000
        for i in range(0,n):
            curr_sum = curr_sum + A[i];
            if(max_sum<curr_sum):
                max_sum = curr_sum
            if(curr_sum<0):
                curr_sum = 0
            
        return max_sum

