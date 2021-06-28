# Given an array of real numbers greater than zero in form of strings.

# Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 

#  Return 1 for true or 0 for false.

class Solution:
	# @param A : list of strings
	# @return an integer
	def solve(self, A):
        a = float(A[0])
        b = float(A[1])
        c = float(A[2])
        n = len(A)
        if (a + b + c)>1 and (a+b+c)<2:
            return 1
        for i in range(3,n):
            if a + b + c>2:
                if((a>b) and (a>c)):
                    a = float(A[i])
                elif ((b>a) and (b>c)):
                    b = float(A[i])
                elif ((c>a) and (c>b)):
                    c = float(A[i])
            elif (a+b+c<1):
                if((a<b) and (a<c)):
                    a = float(A[i])
                elif ((b<a) and (b<c)):
                    b = float(A[i])
                elif ((c<a) and (c<b)):
                    c = float(A[i])
            else: 
                return 1
        if a+b+c>1 and a+b+c<2:
            return 1;
        return 0