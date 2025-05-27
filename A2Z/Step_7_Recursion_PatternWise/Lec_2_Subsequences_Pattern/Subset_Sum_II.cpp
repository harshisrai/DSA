/* Problem: Subset_Sum_II */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        sort(nums.begin(),nums.end());
        solve(ans, ds, nums, 0);
        return ans; 
    }
    void solve(vector<vector<int>>& ans, vector<int>& ds, vector<int>& arr, int idx){
        ans.push_back(ds);
        for(int i=idx; i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue; 
            ds.push_back(arr[i]);
            solve(ans, ds, arr,i+1); 
            ds.pop_back();
        }

    }
};
