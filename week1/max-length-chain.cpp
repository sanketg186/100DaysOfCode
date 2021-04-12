// Max length chain
// You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
bool cmp( struct val p1,struct val p2){
    if(p1.second<p2.second)
    return true;
    return false;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    int i,j,max_val=0;
    vector<int>dp(n,1);
    sort(p,p+n,cmp);
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if((p[j].second)<(p[i].first)){
                dp[i] = max(dp[i],dp[j]+1);
            }
            
        }
        if(max_val<dp[i])
            max_val=dp[i];
    }
    
    return max_val;
//Your code here
}