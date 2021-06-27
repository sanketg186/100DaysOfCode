 // Trapping Rain Water 
 // Given an array arr[] of N non-negative integers representing the height of blocks. 
 // If width of each block is 1, compute how much water can be trapped between the blocks during 
 // the rainy season. 

 #include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        vector<int> left(n,0),right(n,0);
        int i,res =0;
        
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(i=1;i<n;i++){
            left[i] = max(arr[i],left[i-1]);
        }
        for(i=n-2;i>=0;i--){
            right[i] = max(arr[i],right[i+1]);
        }
        
        for(i=1;i<n-1;i++){
            res = res + min(left[i],right[i]) - arr[i];
        }
        
        return res;
    }
    
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends