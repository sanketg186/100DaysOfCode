 // Temple Offerings
 // Consider a devotee wishing to give offerings to temples along a mountain range. 
// The temples are located in a row at different heights. Devotee is very religious and 
// wants to offer each temple at least one offering. If two adjacent temples are at different altitudes, 
// then the temple that is higher up should receive more offerings than the one that is at lower altitude. 
// If two adjacent temples are at the same height, then their offerings relative to each other does not matter. 
// The height of the N temples are given in the array arr[]. Find the minimum number of offerings required.



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int offerings(int N, int arr[]){
        // code here
        vector<int>dp1(N,0),dp2(N,0);
        int offer = 1,sum = 0,i;
        dp1[0] = offer;
        for(i=1;i<N;i++){
            if(arr[i-1]<arr[i]){
              dp1[i] = offer+1;
              offer++;
            }
            else if(arr[i-1]>=arr[i]){
                offer = 1;
                dp1[i]=offer;
            }
        }
        offer = 1;
        dp2[0] = offer;
        reverse(arr,arr+N);
        for(i=1;i<N;i++){
            if(arr[i-1]<arr[i]){
              dp2[i] = offer+1;
              offer++;
            }
            else if(arr[i-1]>=arr[i]){
                offer = 1;
                dp2[i]=offer;
            }
        }
        reverse(dp2.begin(),dp2.end());
        for(i=0;i<N;i++){
            // cout<<dp1[i]<<" "<<dp2[i]<<endl;
            sum = sum + max(dp1[i],dp2[i]);
        }
        
    return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.offerings(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends