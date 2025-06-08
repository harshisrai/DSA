/* Problem: Reverse_Every_Word_in_A_String */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word, res=""; 
        while(iss >> word){
        //    res = word + ((res=="")?"":" ") + res;  
           res = word + (res.empty()?"":" ") + res; //adding space once first word is added
        }
        return res;
    }
};