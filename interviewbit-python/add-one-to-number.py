# Add One To Number
# Given a non-negative number represented as an array of digits,
# add 1 to the number ( increment the number represented by the digits ).
# The digits are stored such that the most significant digit is at the head of the list.

# Example:
# If the vector has [1, 2, 3]
# the returned vector should be [1, 2, 4]
# as 123 + 1 = 124.

class Solution:
    # @param A : list of integers
    # @return a list of integers
    def plusOne(self, A):
        c = 1
        B = A[::-1]
        i=0
        for i in range(0,len(A)):
            if A[i]!=0:
                break;
        A = A[i:]
        B = A[::-1]
        for i in range(0,len(B)):
            s = c + B[i]
            B[i] = int(s%10)
            c = int(s/10)
        
        if(int(c)!=0):
            B.append(c)
        
        return B[::-1]




