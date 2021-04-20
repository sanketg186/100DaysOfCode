// Maximum path sum in matrix
// Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

//     Matrix [r+1] [c]
//     Matrix [r+1] [c-1]
//     Matrix [r+1] [c+1]

// â€‹Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int n=N;
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        int i,j,max_sum=0;
        if(n==1)
        return Matrix[0][0];
        else{
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dp[i][j] =Matrix[i-1][j-1] + max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j]); 
            }
            
        }
        
        for(i=1;i<=n;i++){
            max_sum =max(dp[n][i],max_sum);
        }
        return max_sum;
        }
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends