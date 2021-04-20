 // Longest Common Substring 

 // Given two strings. The task is to find the length of the longest common substring.


 #include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int i,j,max_val=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(i=1;i<=n;i++){
            
            for(j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
                else
                dp[i][j] = 0;
            
            max_val = max(dp[i][j],max_val);
            }
        }
        /*
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return max_val;
        // your code here
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends