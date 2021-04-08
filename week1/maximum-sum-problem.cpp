// Maximum Sum Problem

// A number n can be broken into three parts n/2, n/3 and n/4 (consider only integer part). Each number obtained in this process can be divided further recursively. Find the maximum sum that can be obtained by summing up the divided parts together.
// Note: The maximum sum may be obtained without dividing n also.

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //method-1
    int iterative(int n,vector<int>&dp){
        int i;
        for(i=1;i<=n;i++){
            dp[i] = max(dp[i/2]+dp[i/3]+dp[i/4],i);
        }
        
        return dp[n];
    }
    
    //method-2
    int recur(int n,vector<int>&dp){
        int sum=0;
        if(n==0)
        return 0;
        if(dp[n])
        return dp[n];
        
        sum = max(n/2,recur(n/2,dp)) + max(n/3,recur(n/3,dp))+max(n/4,recur(n/4,dp));
        dp[n]=sum;
        return dp[n];
    }
    
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n+1,0);
            int res;
            //method-1
            // res = recur(n,dp);
            //method-2
            res = iterative(n,dp);
            return res;
        }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends