//  0 - 1 Knapsack Problem 

//  You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Returns the maximum value that  
    // can be put in a knapsack of capacity W 
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(W+1,vector<int>(n,0));
       int i,j;
       for(i=0;i<=W;i++){
           for(j=0;j<n;j++){
               if(i>=wt[j])
               dp[i][j] = max(dp[i-wt[j]][j-1]+val[j],dp[i][j-1]);
               else
               dp[i][j] = dp[i][j-1];
           }
       }
       
       return dp[W][n-1];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends