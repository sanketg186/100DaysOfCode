 // Minimum steps to minimize n as per given condition 

 // Given a number N, the task is to count minimum steps to minimize it to 1 according to the following criteria:

 //    If N is divisible by 2 then you may reduce N to N/2.
 //    If N is divisible by 3 then you may reduce N to N/3.
 //    Otherwise, Decrement N by 1.

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int recur(int N,vector<int>&dp){
	    int r1=INT_MAX,r2=INT_MAX,r3=INT_MAX;
	    if(dp[N]!=INT_MIN)
	    return dp[N];
	    if(N==1)
	    return 0;
	    if(N%2==0){
	        r1 = recur(N/2,dp);
	    }
	    if(N%3==0){
	        r2 = recur(N/3,dp);
	    }
	    
	    if(N-1>=1){
	       r3 = recur(N-1,dp);
	    }
	    dp[N] = 1+ min(r1,min(r2,r3));
	    
	    return dp[N];
	}
	int minSteps(int N) 
	{ 
	    int res=0;
	    vector<int>dp(N+1,INT_MIN);
	    res = recur(N,dp);
	    return res;
	    // Your code goes here
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends