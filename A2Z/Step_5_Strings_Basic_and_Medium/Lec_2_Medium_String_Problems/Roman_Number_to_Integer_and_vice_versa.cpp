/* Problem: Roman_Number_to_Integer_and_vice_versa */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        //I,II, III, IV, V, VI, VII, VIII, IX, X,XI, XII - just to get hint on the pattern
        
        // unordered_map<char,int> val={
        //     {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        // };        
        
        //for faster code on leetcode: 
        int val[128] = {};  // all ASCII chars initialized to 0
        val['I'] = 1; val['V'] = 5; val['X'] = 10;
        val['L'] = 50; val['C'] = 100; val['D'] = 500; val['M'] = 1000;


        for(int i=0;i<s.size();i++){
            if(i!=s.size()-1 && val[s[i]]<val[s[i+1]]) ans-=val[s[i]];
            // if somethin which has a lesser values comes before high value char, subtract the lower val first
            else ans+=val[s[i]];
        }
        return ans;
    }
};