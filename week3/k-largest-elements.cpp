// k largest elements

// Given an array Arr of N positive integers, find K largest elements from the array. 
// The output elements should be printed in decreasing order.

#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    int i;
	    priority_queue<int,vector<int>,greater<int>>pq;
	     vector<int>res(k,0);
	    for(i=0;i<k;i++)
	    pq.push(arr[i]);
	    for(i=k;i<n;i++){
	        if(pq.top()<arr[i]){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	   for(i=0;i<k;i++){
	       res[k-i-1] = pq.top();
	       pq.pop();
	   }
	   return res;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends