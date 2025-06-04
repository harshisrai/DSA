/* Problem: Single_element_in_a_Sorted_Array */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;

        if(l==r) return nums[l]; //single element
        else if(nums[0]!=nums[1]) return nums[0]; //first differs
        else if(nums[r-1]!=nums[r]) return  nums[r]; //last differs
        l+=2;
        r-=2;
        // we took out the extremes, to avoid error in +1. -1 qrithemtic index error 
        while(l<=r){
            int mid=(l+r)/2;
            
            if(nums[mid]==nums[mid+1]){
                if(mid&1) r=mid-1; //odd,even
                else l=mid+2;//even,odd
            }
            else if(nums[mid]==nums[mid-1]){
                if(mid&1) l=mid+1;//even,odd
                else  r=mid-2;  //odd,even
            }
            else return nums[mid];
        }
        return -1;
    }
};