//  Sort an array of 0s, 1s and 2s 
//  Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

 #include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
      int a0=0,a1=0,a2=0,i;
      for(i=0;i<n;i++){
          if(a[i]==0)
          a0++;
          if(a[i]==1)
          a1++;
          else
          a2++;
      }
      
      for(i=0;i<n;i++){
          if(a0>0){
          a[i]=0;
          a0--;
          }
         else if(a1>0){
          a[i]=1;
          a1--;
          }
         else if(a2>0){
             a[i]=2;
             a2--;
         }
      }
        // code here 
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends