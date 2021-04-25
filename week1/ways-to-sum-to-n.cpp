// Ways to sum to N
// Given a set of m distinct positive integers and a value ‘N’. Count the total number of ways we can form ‘N’ by  
// adding the array elements. Repetitions and different arrangements are allowed.
// Note: Answer can be quite large output the answer modulo 109+7.

#include <bits/stdc++.h> 
using namespace std; 
  

 // } Driver Code Ends

int mod = 1000000007;
class Solution
{
  public:
    // function to count the total  
    // number of ways to sum up to 'N' 
    int countWays(int arr[], int M, int N) 
    { 
        // vector<vector<int>> dp(M+1,vector<int>(N+1));
      vector<int>dp(N+1,0);
      //code here.
      int i,j;
      dp[0] = 1;
      for(i=1;i<=N;i++){
          for(j=0;j<M;j++){
              if(i>=arr[j])
              dp[i] = (dp[i] + dp[i-arr[j]])%mod;
          }
      }
      return dp[N];
    //   for(i=0;i<=M;i++)
    //   dp[i][0]=1;
    //   for(i=1;i<=M;i++){
    //       for(j=1;j<=N;j++){
    //           if(j>=arr[i-1]){
    //               dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j];
    //           }
    //           else
    //           dp[i][j] = dp[i-1][j];
    //       }
    //   }
    //   if(N%2==1)
    //   return (dp[M][N]);
    //  return dp[M][N]; 
    } 
    
};


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int m,n ;
	        cin>>m>>n;
	        int arr[m];
	        for(int i = 0;i<m;i++)
	            cin>>arr[i];
	        Solution ob;     
	        cout<<ob.countWays(arr,m,n)<<endl;
	    }
}  // } Driver Code Ends