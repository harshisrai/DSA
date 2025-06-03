/* Problem: Binary_Search_to_find_X_in_sorted_array */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,target,0,nums.size()-1); 
    }
    int binarySearch(vector<int>& nums, int k, int l, int r){
        int mid=(l+r)/2; 
        // if(l==r) return (k==nums[mid])?mid:-1;
        if(l>r) return -1;

        if(nums[mid]>k){r=mid-1;}
        else if(nums[mid]<k){l=mid+1;}
        else return mid; 
        return binarySearch(nums,k,l,r);
    }
};