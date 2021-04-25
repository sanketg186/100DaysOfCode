 Largest square formed in a matrix 

 Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int i,j,max_mat=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(mat[i-1][j-1]==1){
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
                
                max_mat = max(max_mat,dp[i][j]);
            }
        }
        
        return max_mat;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends