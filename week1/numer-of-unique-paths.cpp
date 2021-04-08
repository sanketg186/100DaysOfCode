Number of Unique Paths
Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].


 //Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
        int NumberOfPath(int a, int b) {
        //code here
        int i,j;
        vector<vector<int>> dp(a,vector<int>(b,0));
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                if(i==0||j==0)
                dp[i][j]=1;
                else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[a-1][b-1];
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends