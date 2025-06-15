/* Problem: Remove_k_Digits */

class Solution {
public:
    string removeKdigits(string num, int k) {
        // if top is bigger & i have enough k, remove it 
        string ans,final_ans; 
        for(char i:num){
            while(!ans.empty() && ans.back()>i && k>0) ans.pop_back(), k--;
            ans.push_back(i); 
        }
        while(k!=0) ans.pop_back(),k--;
        
        int l=0; 
        for(char ch:ans){
            if(ch=='0') l++;
            else break; 
        }
        ans=ans.substr(l);
        return ans.empty()?"0":ans; 
        //rempving starting zeroes
        // k is still left -> 
    }
};