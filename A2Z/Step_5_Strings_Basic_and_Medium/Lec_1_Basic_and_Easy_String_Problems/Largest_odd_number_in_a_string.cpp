/* Problem: Largest_odd_number_in_a_string */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1; 
        string ans="";
        for(;i>=0;i--){
            if((num[i]-'0')%2!=0) break;
        }
        if(i>=0) ans=num.substr(0,i+1);
        // substr 
        //first param is: which index to start from
        //second param is: how many characters, takes every thing post the first param idx if not given
        return ans;
    }
};