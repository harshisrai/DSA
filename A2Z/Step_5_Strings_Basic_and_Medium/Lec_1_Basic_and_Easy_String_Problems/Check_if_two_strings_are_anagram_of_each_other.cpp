/* Problem: Check_if_two_strings_are_anagram_of_each_other */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];
        if(s.size()!=t.size()) return false;
        for(char ch:s) arr[ch-'a']++;
        for(char ch:t) arr[ch-'a']--;

        for(int i:arr){
            if(i!=0) return false; 
        }
        return true;
    }
};