// Pascal Triangle 
// Given a positive integer N, return the Nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the 
// elements of previous row.

#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        int i,j;
        ll mod = 1000000007;
        vector<vector<ll>> dp(n,vector<ll>(n,0));
        
        for(i=0;i<n;i++){
        dp[i][0] = 1;
        dp[i][i] =1;
        }
        for(i=2;i<n;i++){
            for(j=1;j<i;j++){
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        
        return dp[n-1];
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends