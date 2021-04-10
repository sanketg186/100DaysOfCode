// Longest Common Subsequence

// Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution{
    public:
        int lcs(int x, int y, string s1, string s2){
        
        // your code here
        
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        int i,j;
        
        for(i=0;i<=x;i++){
            for(j=0;j<=y;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        
        return dp[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends