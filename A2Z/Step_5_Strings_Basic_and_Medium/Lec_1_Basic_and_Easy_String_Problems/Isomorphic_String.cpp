/* Problem: Isomorphic_String */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr[128]; // s to t mapping
        int arr_[128]; // t to s mapping
        for(int l=0;l<128;l++) arr[l]=0;
        for(int l=0;l<128;l++) arr_[l]=0;
        int i=0;
        while(i<s.size()){
            int k=static_cast<int>(s[i]);
            int j=static_cast<int>(t[i]);
            if(arr[k]!=0 && arr_[j]!=0){
                if(j!=arr[k]) return false;
                if(k!=arr_[j]) return false;
            }
            else if(arr[k]==0 && arr_[j]==0){
                arr[k]=j;
                arr_[j]=k;
            }
            else return false;
            i++;
        }
        return true;
    }
};

/*
Mine initial mistake was to just create one arr : s to t mapping 
& because of that both: "AA" was able to map "AB
by A->A
B->A
but there was need of both arrs to check if both mappings are valid
"*/