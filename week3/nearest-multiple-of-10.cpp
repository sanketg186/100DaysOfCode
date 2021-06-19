// Nearest multiple of 10

// Given a string  N representing a positive number. The task is to round N to the nearest 
// multiple of 10.
// Note: If you are having two multiple equally apart from N then we will choose the smallest 
// element among them.

#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    string roundToNearest(string N) 
    { 
        // Complete the function    
        int size = N.size();
        int num = N[size-1] - 48;
        int s=0,i=0;
        if(num==5){
            s = -5;
        }
        else if(num>5){
            s = 10 -num;
        }
        else if (num<5 && num>=1){
            s = s - num;
        }
        else {
            return N;
        }
        i=size-1;
        int c=s;
        while(i>=0){
          num = N[i] -48;
          num = num + c;
          N[i] = (num%10+48);
          c = num/10;
          i--;
        }
        if(c!=0)
        N = to_string(c)+N;
        return N;
    }  

};

// { Driver Code Starts.

int main() {
    
    int t;cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout << ob.roundToNearest(s) << endl;
    }
    
	return 0;
}  // } Driver Code Ends