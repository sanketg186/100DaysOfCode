 // Job Sequencing Problem 

 // Given a set of N jobs where each job i has a deadline and profit associated to it. 
 // Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if 
 // the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

 // Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends


bool cmp(struct Job a,struct Job b){
        if(a.profit>b.profit){
         return 1;   
        }
        
        return 0;
    }

class Solution 
{
    public:
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>slot(n,0);
        int i,j,res=0;
        vector<int> out(2,0);
        // for(i=0;i<3*n;i=i+3){
        //     dp.push_back(make_pair(arr[i+1],arr[i+2]));
        // }
        
        sort(arr,arr+n,cmp);
        
        int num=0;
        for(i=0;i<n;i++){
            
            for(j=min(n,arr[i].dead)-1;j>=0;j--){
                if(slot[j]==0){
                    slot[j]=1;
                    res = res+arr[i].profit;
                    num++;
                    break;
                }
            }
            
        }
        out[0]=num;
        out[1]=res;
        return out;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends