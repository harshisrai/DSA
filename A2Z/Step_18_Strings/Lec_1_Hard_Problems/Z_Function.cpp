/* Problem: Z_Function */

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int n=0;n<haystack.size();n++){
            int pt1=n;
            for(int m=0;m<needle.size();m++){
                if(haystack[pt1]==needle[m]){
                    if(m==needle.size()-1) return n;
                    pt1++;
                }
                else break;
            }
        }
        return -1;
    }
};