// Ease the Array 
// Given an array of integers of size, N. Assume ‘0’ as the invalid number and all others 
// as a valid number. Write a program that modifies the array in such a way that if the next 
// number is a valid number and is the same as the current number, double the current number 
// value and replace the next number with 0. After the modification, rearrange the array such 
// that all 0’s are shifted to the end and the sequence of the valid number or new doubled number 
// is maintained as in the original array.

#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;
     cin>>t;
     while(t--){
         int n,i;
         cin>>n;
         vector<int>a(n,0);
         
         for(i=0;i<n;i++)
         cin>>a[i];
         
         for(i=0;i<n;i++){
             if(a[i]==a[i+1]&&a[i]!=0){
                a[i]=2*a[i];
                a[i+1]=0;
                i++;
             }
             
         }
         vector<int>res(n,0);
         int k=0;
         for(i=0;i<n;i++){
             if(a[i]!=0)
             res[k++]=a[i];
         }
         
       for(i=0;i<n;i++)
       cout<<res[i]<<" ";
       cout<<endl;
         
         
     }
	//code
	return 0;
}