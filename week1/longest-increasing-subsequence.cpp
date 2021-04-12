// Longest Increasing Subsequence 
// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t,i,j,n;
     cin>>t;
     while(t--){
         int x;
         cin>>n;
         if(n==0)
          cout<<"0"<<endl;
          else{
         vector<int>arr;
         vector<int>lis(n,1);
         for(i=0;i<n;i++){
             cin>>x;
             arr.push_back(x);
         }
         for(i=1;i<n;i++){
             for(j=0;j<i;j++){
                 
                 if(arr[j]<arr[i]){
                     lis[i]=max(lis[i],lis[j]+1);
                 }
                 
             }
         }
         
         int maxi=lis[0];
         for(i=1;i<n;i++){
             if(maxi<lis[i])
             maxi=lis[i];
         }
         cout<<maxi<<endl;
          }
         //cout<<max_element(arr.begin(),arr.begin()+n)<<endl;
     }
     
	//code
	return 0;
}