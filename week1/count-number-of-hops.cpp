 // Count number of hops

 // A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. 
 // As the answer will be large find the answer modulo 1000000007.


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to count the number ofA frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007. ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<int>dp(n+1,0);
        int i;
        dp[0]=1;
        for(i=1;i<=n;i++){
            dp[i] = dp[i-1];
            if(i>=2)
            dp[i] = (dp[i]+dp[i-2])%1000000007;
            if(i>=3)
            dp[i] = (dp[i]+dp[i-3])%1000000007;
        }
        
        return dp[n];
        
        // your code here
        
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends