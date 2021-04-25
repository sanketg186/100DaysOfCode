 nCr 
 Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

 // Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
long long mod = 1000000007;
class Solution{
public:
    int nCr(int n, int r){
        // code here
        vector<vector<int>>dp(n+1,vector<int>(r+1,0));
        int i,j;
        for(i=0;i<=n;i++){
            for(j=0;j<=min(i,r);j++){
                if(j==0||i==j)
                    dp[i][j]=1;
                else{
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                }
            }
        }
        
        return dp[n][r];
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends