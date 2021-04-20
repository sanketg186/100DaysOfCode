// Edit Distance

// Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

//     Insert
//     Remove
//     Replace

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int i,j,s_len=s.size(),t_len=t.size();
        vector<vector<int>>dp(s_len+1,vector<int>(t_len+1,0));
        
        for(i=0;i<=s_len;i++){
            
            for(j=0;j<=t_len;j++){
                if(i==0){
                    dp[i][j] = j;
                }
                else if(j==0){
                    dp[i][j] = i;
                }
                else {
                    if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                    else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
            }
        }
        
        return dp[s_len][t_len];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends