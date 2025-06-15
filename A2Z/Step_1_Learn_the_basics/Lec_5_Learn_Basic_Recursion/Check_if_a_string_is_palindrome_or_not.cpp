/* Problem: Check_if_a_string_is_palindrome_or_not */

class Solution {
public:
    bool isPalindrome(string s) {
        string s_="";
        for(char ch:s){
            if(isalnum(ch)){
                if(isalpha(ch))s_.push_back(tolower(ch)); 
                else s_.push_back(ch);
            } 
        }
        s=s_;

        int mid=s.size()/2;
        int k=s.size()-1,i=0;  
        while(i<mid){
            if(s[i]!=s[k-i]) return false; 
            i++;
        }
        return true; 
    }
};