/* Problem: Find_the_first_or_last_occurrence_of_a_given_number_in_a_sorted_array */

#include<bits/stdc++.h>
using namespace std;
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans; 
            ans.push_back(start(nums,target,0,nums.size()-1));
            ans.push_back(end(nums,target,0,nums.size()-1));
            return ans;
        }
        int start(vector<int>& nums, int k, int l,int r){
            if(l>r) return -1;
            int mid=(l+r)/2; 
            if(nums[mid]>k){r=mid-1;}
            else if(nums[mid]<k){l=mid+1;}
            else{
                if(mid==0 || nums[mid-1]!=nums[mid]) return mid; 
                else r=mid-1;
            } 
            return start(nums,k,l,r);
        }
        int end(vector<int>& nums, int k, int l,int r){
            if(l>r) return -1;
            int mid=(l+r)/2; 
            if(nums[mid]>k){r=mid-1;}
            else if(nums[mid]<k){l=mid+1;}
            else {
                if(mid==nums.size()-1 || nums[mid]!=nums[mid+1]) return mid; 
                else l=mid+1;
            } 
            return end(nums,k,l,r);
        }
    };

    /*
    Doing two binary searches ensure O(log n) complexity to find both start and end,
    Initally I was tempted to think that first search then using loop or recursion with two pointers
    get the start and end - But in the worst case it can become O(n) so we had to do two BS to 
    ensure O(log n)
    */