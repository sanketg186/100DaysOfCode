//  Largest subarray with 0 sum 
//  Given an array having both positive and negative integers. 
//  The task is to compute the length of the largest subarray with sum 0.


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function*/
int maxLen(int A[],int n)
{
    unordered_map<long long, int>hash;
    int i;
    int sum=0;
    int max_len=0;
    for(i=0;i<n;i++){
        
        sum=sum+A[i];
        if (A[i]==0 && max_len==0)
            max_len = 1;
        if (sum == 0)
            max_len = i+1;
        if(hash.find(sum)!=hash.end()){
            max_len=max(max_len,i-hash[sum]);
        }
        else{
            hash[sum]=i;
        }
        
    }
    return max_len;
  //Your code here
}
