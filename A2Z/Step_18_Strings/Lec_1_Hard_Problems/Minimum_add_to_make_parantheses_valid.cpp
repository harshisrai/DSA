/* Problem: Minimum_add_to_make_parantheses_valid*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int left=0;
        for(char ch:s){
            if(ch==')'){
                if(left==0) count++;
                else {count--;left--;}
            }
            else {count++; left++;}
        }
        return count;
    }
};