/* Problem: Search_in_Rotated_Sorted_Array_I */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int k, int l=0,int r=-10) {
        if (r == -10) r = nums.size() - 1;
        int mid=(l+r)/2;
        if(l>r) return -1;

        if(nums[mid]==k) return mid;
        else if(nums[l]<=nums[mid]){
            if(nums[mid]>k && nums[l]<=k) return binarySearch(nums,k,l,mid-1);
            else return search(nums,k,mid+1,r);
        }
        else{
            if(nums[mid]<k && nums[r]>=k) return binarySearch(nums,k,mid+1,r);
            else return search(nums,k,l,mid-1);
        }
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


// LOOP BASED METHOD: 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target) return mid;

            // Check if left half is sorted
            if (nums[l] <= nums[mid]) {
                // Target lies in left half
                if (nums[l] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // Right half is sorted
            else {
                // Target lies in right half
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return -1; // Target not found
    }
};

/* 
Main concept - is find the sorted half where my number lies *and you do this using - comparing your low
with the mid, if it's small - it is sorted else it isn't. 

You keep looking for the sorted part where your target can lie - between mid and the extreme => 
Simply apply Binary Search post that point. */