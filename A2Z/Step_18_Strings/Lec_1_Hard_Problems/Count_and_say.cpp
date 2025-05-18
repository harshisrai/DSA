/* Problem: Count_and_say */
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        return rle(countAndSay(n-1));
    }

    string rle(string s){
        reverse(s.begin(),s.end());
        string res="";
        char pt=' ';
        int count=0;
        for(char ch:s){
            if(pt==' '){
                pt=ch;
                count++;
            }
            else if(pt==ch){
                count++;
            }
            else{
                res.push_back(pt);
                res.push_back(count+'0'); 
                count=1;
                pt=ch; 
            } 
        }
        res.push_back(pt);
        res.push_back(count+'0'); 
        reverse(res.begin(),res.end());
        cout<<res<<endl;
        return res; 
    }
};