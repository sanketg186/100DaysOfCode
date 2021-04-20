// Matrix Chain Multiplication

// Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
// The efficient way is the one that involves the least number of multiplications. The dimensions of the matrices 
// are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,0));
        int num_mat=N-1,temp,i,j,l,k;
        for(l=2;l<=num_mat;l++){
            for(i=0;i<N-l;i++){
                int j=i+l;
                dp[i][j]=INT_MAX;
                for(k=i+1;k<j;k++){
                    
                    temp = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
                    if(temp<dp[i][j])
                    dp[i][j] = temp;
                }
            }
        }
        return dp[0][N-1];
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends