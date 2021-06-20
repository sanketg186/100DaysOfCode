# Minimum Lights to Activate
# There is a corridor in a Jail which is N units long. Given an array A of size N. 
# The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.
# All the lights are of specific power B which if is placed at position X, it can light the 
# corridor from [ X-B+1, X+B-1].
# Initially all lights are off.
# Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the 
# whole corridor cannot be lighted.




class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        n = len(A)
        i=0
        flag = 0;
        res = 0;
        while(i<n):
            s = max(0,i-B+1)
            e = min(n-1,i+B-1)
            flag = 0;
            while(s<=e):
                if(A[e]==1):
                    i = e +B;
                    flag = 1;
                    res = res +1;
                    break;
                e=e-1;
            if(flag==0):
                res = -1;
                break;
        return res;