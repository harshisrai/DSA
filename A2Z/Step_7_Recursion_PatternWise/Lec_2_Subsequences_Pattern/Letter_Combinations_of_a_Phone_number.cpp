/* Problem: Letter_Combinations_of_a_Phone_number */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> map={"abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  
        solve(ans,map, digits, "",0);
        return ans;
    }
    void solve(vector<string>& ans, vector<string>& map, string digits, string s, int idx){
        if(idx==digits.size()){
            if(idx!=0) ans.push_back(s);
            return;
        }
        string f= map[digits[idx]-'2']; 
        for(char ch:f){
            s.push_back(ch); 
            solve(ans, map, digits, s, idx+1);
            s.pop_back();
        }
    }
};