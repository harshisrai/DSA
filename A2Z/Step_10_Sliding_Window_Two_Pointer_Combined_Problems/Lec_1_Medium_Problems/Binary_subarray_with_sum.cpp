/* Problem: Binary_subarray_with_sum */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0,r=0; 
        int ans1=0,ans2=0,sum=0;
        //first calc <=goal & then <=goal-1 & then you will get for goal by subtracting
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal) sum-=nums[l],l++;
            if(sum<=goal) ans1+=(r-l+1); 
            r++;
        }
        sum=0,r=0,l=0;
        if(goal==0) ans2=0;
        else{
            while(r<nums.size()){
                sum+=nums[r];
                while(sum>goal-1) sum-=nums[l],l++;
                if(sum<=goal-1) ans2+=(r-l+1); 
                r++;
            }
        }
        // cout<<ans1<<" "<<ans2<<endl;
        return ans1-ans2; 
    }
};