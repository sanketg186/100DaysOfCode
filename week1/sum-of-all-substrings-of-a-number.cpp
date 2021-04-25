// Sum of all substrings of a number
// Given an integer S represented as a string, the task is to get the sum of all possible sub-strings of this string.
// As the answer will be large, print it modulo 10^9+7.

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

long long mod=1000000007;

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        int n = s.size();
        long long sum=0,i;
        vector<long long> dp(n+1,0);
        
        for(i=1;i<=n;i++){
            dp[i] = ((i*(s[i-1]-48))%mod+(10*dp[i-1])%mod)%mod;
            sum = (sum+dp[i])%mod;
        }
        
        return sum;
        // your code here
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
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}
  // } Driver Code Ends