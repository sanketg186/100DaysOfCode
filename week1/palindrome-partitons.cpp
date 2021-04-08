
// Find all possible palindromic partitions of a String

// Given a String S, Find all possible Palindromic partitions of the given String.

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int ifpalindrome(string s){
      int i,len = s.size()-1;
      for(i=0;i<=len;i++){
          
          if(s[i]!=s[len])
          return 0;
          len--;
      }
      return 1;
  }
  void recur(string s,int index,vector<string>&temp,vector<vector<string>>&res){
      
      string str = "";
      int len = s.size(),i;
      for(i=index;i<s.size();i++){
          str = str + s[i];
          
          if(ifpalindrome(str)){
              temp.push_back(str);
              if(i+1<len){
                  recur(s,i+1,temp,res);
              }
              else{
                  res.push_back(temp);
              }
              temp.pop_back();
          }
          
      }
      return;
      
  }
    vector<vector<string>> getGray(string S) {
        // code here
        vector<vector<string>>res;
        vector<string>temp;
        temp.clear();
        res.clear();
        recur(S,0,temp,res);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.getGray(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends