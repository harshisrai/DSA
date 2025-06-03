/* Problem: Search_Insert_Position */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,target, 0, nums.size()-1, 0); 
    }

    int binarySearch(vector<int>& nums, int k, int l, int r, int idx){
        if(l>r) return idx; 
        int mid=(l+r)/2;
        if(nums[mid]>k) return binarySearch(nums,k,l,mid-1,mid);
        else if(nums[mid]==k) return mid; 
        else return  binarySearch(nums,k,mid+1,r,mid+1);
    }
};