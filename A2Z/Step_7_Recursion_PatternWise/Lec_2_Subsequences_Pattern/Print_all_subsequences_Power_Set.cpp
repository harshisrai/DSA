/* Problem: Print_all_subsequences_Power_Set */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        solve(ans, ds, nums, 0);
        return ans;
    }
    void solve(vector<vector<int>>& ans, vector<int>& ds,vector<int>& nums, int idx){
        if(idx==nums.size()) {ans.push_back(ds);return;}
        ds.push_back(nums[idx]);
        solve(ans, ds, nums, idx+1);
        ds.pop_back();
        solve(ans, ds, nums, idx+1);
    }
};