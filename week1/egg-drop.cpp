// Egg Dropping Puzzle 
// Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

//     An egg that survives a fall can be used again.
//     A broken egg must be discarded.
//     The effect of a fall is the same for all eggs.
//     If the egg doesn't break at a certain floor, it will not break at any floor below.
//     If the eggs breaks at a certain floor, it will break at any floor above.


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /* Function to get minimum number of trials needed in worst 
      case with n eggs and k floors*/
    int eggDrop(int n, int k) 
    {
        // your code here
        int i,j,x;
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        
        for(i=1;i<=n;i++)
        dp[i][1]=1;
        for(j=1;j<=k;j++)
        dp[1][j]=j;
        
        for(i=2;i<=n;i++){
            for(j=2;j<=k;j++){
                dp[i][j] = INT_MAX;
                for(x=1;x<=j;x++){
                dp[i][j] = min(1+max(dp[i-1][x-1],dp[i][j-x]),dp[i][j]);
                
                }
            }
        }
        return dp[n][k];
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends