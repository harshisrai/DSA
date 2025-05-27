/* Problem: Generate_Paranthesis */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 
        string s; 
        solve(0,0,n,ans,s);
        return ans;
    }
    void solve(int open, int close, int n,vector<string>& ans, string s){
        if(open>close){
            s.push_back(')'); 
            solve(open, close+1, n,ans,s);
            s.pop_back();
        }
        if(open<n){
        s.push_back('(');
        solve(open+1, close, n,ans,s);
        }
        if(close==n) {ans.push_back(s); return;}
    }
};