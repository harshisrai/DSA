/* Problem: Find_the_highest_lowest_frequency_element */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); 
        using ll=long long; 
        //window size = max cost <k
        ll sum=0;
        int window_size=0,ans=0; 
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i]; 
            window_size++;
            // cout<<window_size*nums[i]-sum<<endl;
            if(1ll*window_size*nums[i]-sum>k) window_size--,sum-=nums[i-window_size]; 
            ans=max(window_size, ans); 
        }
        return ans; 
    }
};