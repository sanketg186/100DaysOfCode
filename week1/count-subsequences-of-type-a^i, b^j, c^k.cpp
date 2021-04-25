 Count subsequences of type a^i, b^j, c^k 

 Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.

Note: 
1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
2.  For large test cases, output value will be too large, return the answer MODULO 10^9+7

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 
long long mod = 1000000007;
class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        long long a_count=0,b_count=0,c_count=0;
        int i;
        for(i=0;i<s.size();i++){

            if(s[i]=='a'){
                a_count = (1+2*a_count)%mod;
            }
            else if(s[i]=='b'){
                b_count = (a_count + (2*b_count)%mod)%mod;
            }
            
            else if(s[i]=='c'){
                c_count = (b_count + (2*c_count)%mod)%mod;
            }
            
        }
        
        return c_count;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends