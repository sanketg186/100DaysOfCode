// Reach a given score 
// Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

// Input:
// The first line of input contains an integer T denoting the number of test cases. T testcases follow.The first line of each test case is n.

// Output:
// For each testcase, in a new line, print number of ways/combinations to reach the given score.

// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends


// Complete this function
long long int count(long long int n)
{
	vector<int>dp(n+1,0);
	ll res=0,i;
	dp[0]=1;                 // If 0 sum is required number of ways is 1.
	
for(i=3;i<=n;i++)
dp[i] = dp[i]+dp[i-3];

for(i=5;i<=n;i++)
dp[i] = dp[i]+dp[i-5];

for(i=10;i<=n;i++)
dp[i] = dp[i]+dp[i-10];



	
	// Your code here
	
	return dp[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends