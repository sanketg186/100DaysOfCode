// Kadane's Algorithm 
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int curr_sum=0,max_sum=0,i;
        
        for(i=0;i<n;i++){
            
            curr_sum = curr_sum+arr[i];
            if(max_sum<curr_sum){
                max_sum = curr_sum; 
            }
            if(curr_sum<0)
                curr_sum=0;
            
        }
        return max_sum;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends