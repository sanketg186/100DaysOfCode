// Word Break 
// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int check_dict(string s,vector<string>dict){
    int i,n;
    for(i=0;i<dict.size();i++){
        if(dict[i].compare(s)==0)
        return 1;
    }
    return 0;
}

int iter(string s,vector<string>dict){
    
    int n = s.size();
    vector<int>dp(n+1,0);
    int i,j;
    for(i=1;i<=n;i++){
        
        if(dp[i]==0 &&check_dict(s.substr(0,i),dict))
        dp[i]=1;
        
        if(dp[i]==1){
            for(j=i+1;j<=n;j++){
                
                if(dp[j]==0&&check_dict(s.substr(i,j-i),dict)){
                    dp[j]=1;
                    
                }
                
                if(j==n&&dp[j]==1)
                    return 1;
            }
        }
        
        
    }
    
    return dp[n];
}

int wordBreak(string A, vector<string> &B) {
    //code here
    int res;
    
    res = iter(A,B);

    return res;
}