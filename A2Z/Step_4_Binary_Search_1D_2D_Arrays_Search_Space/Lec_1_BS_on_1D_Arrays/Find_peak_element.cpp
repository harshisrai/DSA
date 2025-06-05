/* Problem: Find_peak_element */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        if(r==0) return 0;
        else if(nums[0]>nums[1]) return 0;
        else if(nums[r]>nums[r-1]) return r;
        l++;r--;
        while(l<=r){
            int mid=(l+r)/2;
            //either on the peak
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid;
            }
            //increasing slope
            else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            //decresing slope
            else if(nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1]){
                r=mid-1;
            }
            //in the valley
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};