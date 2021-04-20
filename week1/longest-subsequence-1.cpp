// Longest subsequence-1 
// Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<int>dp(N+1,0);
        int i,j,max_val=0;
        dp[0]=1;
        max_val=dp[0];
        for(i=1;i<N;i++){
            dp[i]=1;
            for(j=0;j<i;j++){
                if(abs(A[i]-A[j])==1){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            if(max_val<dp[i])
            max_val=dp[i];
        }
        return max_val;
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
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends