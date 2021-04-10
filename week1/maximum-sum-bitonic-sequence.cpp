//  Maximum Sum Bitonic Subsequence 
//  Given an array of integers A. A subsequence of A is called Bitonic if it is first increasing then decreasing.

// Input:
// The first line contains an integer T denoting the no of test cases. Each test case consist of two lines. The first line contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A[].

// Output:
For each test case in a new line print the max sum bitonic subsequence.

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n,i,temp,j;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int>v,dp1(n,0),dp2(n,0);
	    for(i=0;i<n;i++){
	        cin>>temp;
	        v.push_back(temp);
	    }
	    
	    for(i=0;i<n;i++){
	        dp1[i]=v[i];
	        for(j=0;j<i;j++){
	            if(v[j]<v[i]&&dp1[i]<dp1[j]+v[i]){
	                dp1[i] = dp1[j]+v[i];
	            }
	        }
	    }
	    
	    reverse(v.begin(),v.end());
	     for(i=0;i<n;i++){
	         dp2[i] = v[i];
	        for(j=0;j<i;j++){
	            if(v[j]<v[i]&&dp2[i]<dp2[j]+v[i]){
	                dp2[i] = dp2[j]+v[i];
	            }
	        }
	    }
	    reverse(v.begin(),v.end());
	    reverse(dp2.begin(),dp2.end());
	    int max_val = 0;
	    for(i=0;i<n;i++){
	        max_val = max(max_val,dp1[i]+dp2[i]-v[i]);
	    }
	    cout<<max_val<<endl;
	}
	return 0;
}