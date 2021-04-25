// Interleaved Strings
// Given three strings A, B and C your task is to complete the function isInterleave which returns true if C is an interleaving of
// A and B else returns false. C is said to be interleaving A and B, 
// if it contains all characters of A and B and order of all characters in individual strings is preserved.


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int i,j,a = A.size(),b = B.size(), c= C.size();
        vector<vector<int>>dp(a+1,vector<int>(b+1,0));
        
        
        for(i=0;i<=a;i++){
            for(j=0;j<=b;j++){
                
                if(i==0&&j==0)
                    dp[0][0]=1;
                else if(i==0&&B[j-1]==C[j-1]){
                    dp[i][j] = dp[i][j-1];
                }
                else if(j==0&&A[i-1]==C[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(A[i-1]==B[j-1]&&A[i-1]==C[i+j-1]){
                    dp[i][j] = dp[i-1][j]|dp[i][j-1];
                }
                else if (A[i-1]==C[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(B[j-1]==C[i+j-1]){
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        // for(i=0;i<=a;i++){
        //     for(j=0;j<=b;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[a][b];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends