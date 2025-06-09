/* Problem: Max_Consecutive_Ones_III */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int countZero=0,len=0;
        while(r<nums.size()){
            if(nums[r]==0) countZero++;
            if(countZero>k){
                while(countZero>k){
                    if(nums[l]==0) countZero--; 
                    l++;                    
                }
            }
            len=max(r-l+1,len);
            r++;
        }
        return len;
    }
};