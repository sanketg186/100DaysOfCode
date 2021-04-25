 // Maximize The Cut Segments 
 // Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
 // After performing all the cut operations, your total number of cut segments must be maximum.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int recur(vector<int>&dp,int n,int x,int y, int z){
        int r1=INT_MIN,r2=INT_MIN,r3=INT_MIN;
        if(dp[n]!=-1)
        return dp[n];
        if(n==0)
            return 0;
        
        if(n-x>=0)
        r1 = recur(dp,n-x,x,y,z);
        
        if(n-y>=0)
        r2 = recur(dp,n-y,x,y,z);
        
        if(n-z>=0)
        r3 = recur(dp,n-z,x,y,z);
        
        dp[n] = max(r1,max(r2,r3)) + 1;
        
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int i,j,max_val=0,res=0;
        
        vector<int>dp(n+1,-1);
        res = recur(dp,n,x,y,z);
        
        return max(dp[n],0);
        //Your code here
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends

