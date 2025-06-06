/* Problem: Longest_Common_Prefix */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int l=strs.size()-1;
        for(int i=0;i<=l;i++){
            string s=strs[i];
            if(i==0) ans=s;
            else{
                string res="";
                int k=min(ans.size(),s.size());
                for(int i=0;i<k;i++){
                    if(ans[i]==s[i]) res.push_back(s[i]);
                    else break;
                }
                ans=res;  
                if(ans=="") break; 
            }
        }
        return ans;
    }
};