 // Stickler Thief
 // Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution{
    public:
    // Function to return maximum of sum without adjacent elements
    ll FindMaxSum(ll arr[], ll n)
    {
        // Your code here
        vector<int>dp(n+1,0);
        int max_sum=0,i;
        for(i=0;i<n;i++){
            if(i==0 || i==1){
                dp[i]=arr[i];
            }
            else if(i==2){
                dp[i] = dp[i-2] + arr[i];
            }
            else{
            dp[i] = max(dp[i-2],dp[i-3]) + arr[i];
            }
            if(max_sum<dp[i])
            max_sum=dp[i];
        }
    
        return max_sum;
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
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends