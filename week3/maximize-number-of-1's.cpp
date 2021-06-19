//  Maximize Number of 1's

//  Given a binary array arr of size N and an integer M. Find the maximum number of 
//  consecutive 1's produced by flipping at most M 0's.

 #include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int c=0;
        int i=0,j=0;
        int curr=0, max_len=0;
        while(j<n && i<=j){
            
           if(c<=m){

           if(arr[j]==0)
               c++;
               j++;
            //   max_len = max(max_len,curr);
           }
           if(c>m){
               if(arr[i]==0)
               c--;
               i++;
           }
           max_len = max(max_len,j-i);
        }
        
        return max_len;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends