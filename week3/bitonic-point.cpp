// Bitonic Point

// Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
// Note: If the array is increasing then just print then last element will be the maximum value.


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int binary(int start,int end,int arr[]){
	    int mid = (start+end)/2;
	    if(start<=end){
	        
	        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
	            return arr[mid];
	        }
	        else if (arr[mid]<arr[mid+1])
	        return binary(mid+1,end,arr);
	        else binary(start,mid-1,arr);
	    }
	}
	int findMaximum(int arr[], int n) {
	    // code here
	    int s=0,e = n-1,m;
	    int max_e=0;
	    max_e = binary(0,n-1,arr);
	    
	    return max_e;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends