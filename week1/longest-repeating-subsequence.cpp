// Longest Repeating Subsequence

// Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size(),i,j;
		    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
		    
		    for(i=1;i<=n;i++){
		        
		        for(j=1;j<=n;j++){
		            
		            if(str[i-1]==str[j-1]&&i!=j){
		                dp[i][j] = dp[i-1][j-1] +1;
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
		            }
		        }
		    }
		    
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends