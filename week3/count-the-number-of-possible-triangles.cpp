//  Count the number of possible triangles 
//  Given an unsorted array arr[] of n positive integers. 
//  Find the number of triangles that can be formed with three different array elements as 
//  lengths of three sides of triangles. 

 #include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n);
        int i,j,k,l,r,num=0;
        i=0;j=1;k=2;
        for(i=n-1;i>1;i--){
            l=0;
            r = i-1;
            while(l<r){
                if(arr[l]+arr[r]>arr[i]){
                    num =num + r-l;
                    r--;
                }
                else
                l++;
            }
        }
        return num;
        
        // code here
    }
};


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}  // } Driver Code Ends
