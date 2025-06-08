/* Problem: Floor_Ceil_in_Sorted_Array */
#include<bits/stdc++.h>
using namespace std;

// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> ans;
        int a=INT_MIN,b=INT_MAX; //ceil,floor
        for(int n:arr){
            if(n==x) {a=x;b=x;break;}
            else if(n>x) b=min(n,b);
            else{
                a=max(n,a);
            }
        }
        if(a==INT_MIN) a=-1;
        if(b==INT_MAX) b=-1;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};