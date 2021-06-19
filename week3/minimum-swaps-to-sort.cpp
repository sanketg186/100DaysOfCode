//  Minimum Swaps to Sort 
//  Given an array of n distinct elements. 
//  Find the minimum number of swaps required to sort the array in strictly increasing order.

 #include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int num_cycle(vector<int>&visit,pair<int,int>arr[],int i){
	    if(visit[i]==1)
	    return 0;
	    if(visit[i]==0){
	        visit[i]=1;
	        return 1+num_cycle(visit,arr,arr[i].second);
	    }
	    return 0;
	}
	int minSwaps(vector<int>&nums)
	{
	    int res=0,n = nums.size(),i;
	    pair<int,int> arr[n];
	    vector<int> visit(n,0);
	    for(i=0;i<n;i++){
	        arr[i].first = nums[i];
	        arr[i].second = i;
	    }
	    sort(arr,arr+n);
	    int temp;
	    for(i=0;i<n;i++){
	        if(arr[i].second==i)
	        visit[i]=1;
	        else{
	        temp = num_cycle(visit,arr,i);
	        if(temp>0)
	        res = res +temp-1;
	        }
	    }
	    
	    return res;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends