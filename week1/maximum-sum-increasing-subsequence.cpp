// Maximum sum increasing subsequence

// Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int i,j,max_val=0;
	    vector<int>dp(n,0);
	    
	    for(i=0;i<n;i++){
	        dp[i] = arr[i];
	        for(j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                dp[i] = max(dp[i],dp[j] + arr[i]);
	            }
	        }
	        
	        max_val = max(max_val,dp[i]);
	    }
	 
	 return max_val;  
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends