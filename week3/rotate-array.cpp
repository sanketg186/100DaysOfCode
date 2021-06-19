 Rotate Array 
 Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    
    int gcd(int a,int b){
        if(b==0)
        return a; 
        
        return gcd(b,a%b);
        
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        int k,j,i,temp,size;
        d = d%n;
        size = gcd(n,d);
        for(i=0;i<size;i++){
            temp = arr[i];
            j=i;
            while(1){
                k=j+d;
                if(k>=n)
                k = k-n;
                if(k==i)
                break;
                
                arr[j] = arr[k];
                j = k;
            }
            arr[j] = temp;
        }
        
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends