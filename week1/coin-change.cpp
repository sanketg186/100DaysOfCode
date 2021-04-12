// Coin Change 
// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        long long i,j;
        for(i=0;i<=m;i++)
        dp[i][0]=1;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
               if(j-S[i-1]>=0){
                   dp[i][j] =dp[i][j-S[i-1]]+ dp[i-1][j];
               } 
               else{
                   dp[i][j]=dp[i-1][j];
               }
            }
        }
       
       return dp[m][n];
        //code here.
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends