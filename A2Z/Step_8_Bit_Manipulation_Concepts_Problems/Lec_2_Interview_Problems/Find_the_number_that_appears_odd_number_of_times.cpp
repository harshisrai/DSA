/* Problem: Find_the_number_that_appears_odd_number_of_times */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0; 
        for(int n:nums){
            res=res^n;
        }
        return res; 
    }
};