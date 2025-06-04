/* Problem: Find_minimum_in_Rotated_Sorted_Array */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            if(nums[l]<=nums[r]) return nums[l];
            int mid=(l+r)/2;
            if(mid>0 && nums[mid-1]>nums[mid]) return nums[mid]; //if the smallest is the middle
            else if(nums[l]<=nums[mid]) l=mid+1; //if smallest is on right
            else r=mid-1; // if smallest is on left
        }
        return -1; 
    }
};

//My way of finding minimum 