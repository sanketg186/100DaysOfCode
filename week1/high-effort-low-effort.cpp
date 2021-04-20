// High Effort vs Low Effort

// You are given n days and for each day (di) you can select one of the following options:

//     perform no task 
//     perform a high effort task (hi) only if its the first day or if you chose no-task on the previous day
//     perform a low effort task (li)

// Write a program to find the maximum amount of tasks you can perform within these n days. 

#include <iostream>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
        int maxAmt(int n , int hi[] , int li[])
        {
            int dp[n];
            int i;
            dp[0] = hi[0];
            for(i=1;i<n;i++){
               if(i==1)
               dp[i] = max(hi[i],dp[i-1]+li[i]);
               else
               dp[i] = max(dp[i-1]+li[i], dp[i-2]+hi[i]);
                }
        return dp[n-1];
            //code here.    
            
        }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            int n;
            cin>>n;
            int hi[n] , li[n];
            for(int i = 0 ;i<n;i++)
                cin>>hi[i];
            for(int i = 0 ;i<n;i++)
                cin>>li[i];
            Solution ob;
            cout<<ob.maxAmt(n,hi,li)<<endl;    
        }
}  // } Driver Code Ends