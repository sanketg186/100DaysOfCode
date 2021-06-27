 // Top K Frequent Elements in Array
 // Given a non-empty array of integers, find the top k elements which have the highest frequency in the 
 // array. If two numbers have the same frequency then the larger number should be given preference.

 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  static int cmp(pair<int,int>a,pair<int,int>b){
      if(a.second>b.second)
      return 1;
      else if (a.second==b.second) {
          if (a.first>b.first)
          return 1;
          else 
          return 0;
      }
      else 
      return 0;
  }
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        int n=nums.size(),i;
        unordered_map<int,int>hash;
        vector<int>res;
        hash.clear();
        for(i=0;i<n;i++){
            if(hash.find(nums[i])==hash.end())
            hash[nums[i]] = 1;
            else{
            hash[nums[i]]= hash[nums[i]]+1;
            }
        }
        vector<pair<int,int>> v(hash.begin(),hash.end());
        sort(v.begin(),v.end(),cmp);
        for(i=0;i<k;i++){
        res.push_back(v[i].first);
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends