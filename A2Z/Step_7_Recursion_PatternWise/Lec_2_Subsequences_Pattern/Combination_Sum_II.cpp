/* Problem: Combination_Sum_II */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        sort(candidates.begin(),candidates.end());
        find(ans, ds, candidates, target, 0); 
        return ans;
    }
    void find(vector<vector<int>>& ans,vector<int>& ds, vector<int>& arr, int target, int idx){
        if(target==0){
            ans.push_back(ds); 
            return; 
        }

        for(int i=idx; i<arr.size(); i++){
            if (i>idx && arr[i]==arr[i-1]) continue;
            if (target<arr[i]) break;
            ds.push_back(arr[i]);
            find(ans, ds, arr, target-arr[i],i+1); 
            ds.pop_back();
        }
    }
};