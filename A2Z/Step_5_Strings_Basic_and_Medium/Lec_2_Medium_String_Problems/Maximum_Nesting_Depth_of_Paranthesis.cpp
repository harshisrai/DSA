/* Problem: Maximum_Nesting_Depth_of_Paranthesis */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int l=0,m=-1;
        for(char ch:s){
            if(ch=='(')l++;
            else if(ch==')')l--;
            m=max(m,l);
        }
        return m;
    }
};