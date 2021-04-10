
// Knapsack with Duplicate Items

// Given a set of N items, each with a weight and a value, and a weight limit W. Find the maximum value of a collection containing any 
// of the N items any number of times so that the total weight is less than or equal to W.

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(W+1,vector<int>(n,0));
       int i,j;
       for(i=0;i<=W;i++){
           for(j=0;j<n;j++){
               if(i>=wt[j])
               dp[i][j] = max(dp[i-wt[j]][j]+val[j],dp[i][j-1]);
               else
               dp[i][j] = dp[i][j-1];
           }
       }
       
       return dp[W][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends