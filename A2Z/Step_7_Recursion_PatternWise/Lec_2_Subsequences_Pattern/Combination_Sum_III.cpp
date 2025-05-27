/* Problem: Combination_Sum_III */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans, ds,n,k,1); 
        return ans;

    }
    void solve(vector<vector<int>>& ans, vector<int>& ds, int n, int size, int val){
        if(n<val || size==0 || val>9){
            if(n==0 && size==0) ans.push_back(ds);
            return; 
        }

        ds.push_back(val);
        solve(ans,ds,n-val,size-1,val+1);
        ds.pop_back(); 

        solve(ans,ds,n,size,val+1);
    }
};