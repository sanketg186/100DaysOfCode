// Painting the Fence
// Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 
// adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.

#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

int mod=1000000007;
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        
        vector<long long >same(n+1,0),diff(n+1,0),total(n+1,0);
        int i;
        total[1] = k;
        same[1]=0;
        diff[1]=k;
        
        for(i=2;i<=n;i++){
            same[i] = diff[i-1];
            diff[i] = (total[i-1]*(k-1))%mod;
            total[i] = (same[i]+diff[i])%mod;
        }
        
        return total[n];
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends