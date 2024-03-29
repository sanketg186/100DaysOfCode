// Stock span problem
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock 
// and we need to calculate the span of stock’s price for all n days. The span Si of the stock’s price on a 
// given day i is defined as the maximum number of consecutive days just before the given day, for which the 
// price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values 
// or corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       int i;
       stack<int> stk;
       vector<int>res;
       stk.push(0);
       res.push_back(1);
       for(i=1;i<n;i++){
           while(!stk.empty() && price[stk.top()]<=price[i])
           stk.pop();
           if(stk.empty())
           res.push_back(i+1);
           else
           res.push_back(i-stk.top());
           
           stk.push(i);
       }
     
     return res;  
    }
    
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends