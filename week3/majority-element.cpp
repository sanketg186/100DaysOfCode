// Majority Element 
// Given an array A of N elements. Find the majority element in the array. 
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int maj=0,c=1,i;
        for(i=1;i<size;i++){
            if(a[i]==a[maj])
            c++;
            else if(a[i]!=a[maj])
            c--;
            if(c==0){
                maj = i;
                c=1;
            }
        }
        //cout<<c<<" "<<size<<endl;
        c=0;
        for(i=0;i<size;i++){
            if(a[maj]==a[i])
            c++;
        }
        
        if(c<=size/2)
        return -1;
        return a[maj];
        // your code here
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends