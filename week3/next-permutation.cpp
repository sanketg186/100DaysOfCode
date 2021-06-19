//  Next Permutation

//  Implement the next permutation, which rearranges the list of numbers into Lexicographically 
//  next greater permutation of list of numbers. If such arrangement is not possible, 
//  it must be rearranged to the lowest possible order i.e. sorted in an ascending order. 
//  You are given an list of numbers arr[ ] of size N.

 // Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int max=0,val,i=N-1,j;
        while(i>0&&arr[i]<=arr[i-1]){
            i--;
        }
        if(i==0)
            reverse(arr.begin(),arr.end());
        else{
            reverse(arr.begin()+i,arr.end());
            for(j=i;j<N;j++){
                if(arr[i-1]<arr[j]){
                    swap(arr[i-1],arr[j]);
                    break;
                }
            }
        }
        
        // val =arr[i-1];
        // for(j=i+1;j<N;j++){
        //     if(val)
        // }
        return arr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends