/* Problem: Combination_Sum */
#include <bits/stdc++.h>
using namespace std;


/*
Mine/ idea from Leetcode optimal solution=>

Using this approach, you are faster and secondly are able to solve Combination Sum II with some minor tweaks.
So instead of having two different approaches, do one optimal approach - that does it all. 
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        sort(candidates.begin(),candidates.end());
        solve(ans,ds, candidates, target, 0); 
        return ans; 
    }
    void solve(vector<vector<int>>& ans, vector<int>& ds, vector<int>& arr, int target, int idx){
        if(target==0){
            ans.push_back(ds);
            return; 
        }
        for(int i=idx; i<arr.size(); i++){
            if(arr[i]>target) break;
            ds.push_back(arr[i]); 
            solve(ans, ds, arr, target-arr[i],i);
            ds.pop_back(); 
        }
    }
};

/* Striver's Method - not recommended, though can see for understanding.*/
class Solution {
public:
    void find(int idx, int target,vector<int>& candidates,vector<vector<int>>& ans, vector<int> ds){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //pick
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            find(idx, target-candidates[idx],candidates, ans, ds); 
            ds.pop_back();
        }

        find(idx+1, target,candidates, ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> ds; 
        find(0,target,candidates, ans,ds);
        return ans;
    }
};

