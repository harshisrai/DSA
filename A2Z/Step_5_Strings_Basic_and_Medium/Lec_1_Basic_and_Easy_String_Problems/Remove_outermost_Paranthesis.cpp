/* Problem: Remove_outermost_Paranthesis */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
    //primitive: all opens are closed (start printing whenever open=1 & stop when it gets to 0)   
        int l=0;
        string ans="";
        for(char ch:s){
            if(ch=='('){
                l++;
                if(l>1) ans.push_back(ch);
            }
            else {
                l--;
                if(l>0) ans.push_back(ch);
            }
        }
        return ans;
    }
};