/* Problem: Reverse_words_in_a_given_string_Palindrome_Check */
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