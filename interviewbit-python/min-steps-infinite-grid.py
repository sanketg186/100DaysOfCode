# Min Steps in Infinite Grid
# You are in an infinite 2D grid where you can move in any of the 8 directions
#  (x,y) to 
#     (x+1, y), 
#     (x - 1, y), 
#     (x, y+1), 
#     (x, y-1), 
#     (x-1, y-1), 
#     (x+1,y+1), 
#     (x-1,y+1), 
#     (x+1,y-1) 
# You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.
# NOTE: This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.

# Input Format
# Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.

# Output Format
# Return an Integer, i.e minimum number of steps.



class Solution:
	# @param A : list of integers
	# @param B : list of integers
	# @return an integer
	def coverPoints(self, A, B):
        min_step=0
        for i in range(0,len(A)-1):
            min_step = min_step + max(abs(A[i]-A[i+1]),abs(B[i]-B[i+1]))
        
        return min_step