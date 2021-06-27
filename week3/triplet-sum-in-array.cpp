 // Triplet Sum in Array 
 // Given an array arr of size n and an integer X. 
 // Find if there's a triplet in the array which sums up to the given integer X. 
 

 #include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        int i,j,k;
        sort(A,A+n);
        for(i=0;i<n-2;i++){
            j = i+1;
            k = n-1;
            while(j<k){
                int sum = A[i]+A[j]+A[k];
                if(sum==X)
                return 1;
                else if (sum<X)
                j++;
                else
                k--;
            }
        }
        
        return 0;
        
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends