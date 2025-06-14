/* Problem: Next_Greater_Element_2 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int k=nums.size(); 
        vector<int> ans(k,0); 
        stack<int> st; 
        int n=2*k-1; 
        for(;n>=0; n--){
            int idx=n%k; 
            while(!st.empty() && st.top()<=nums[idx]) st.pop();
            ans[idx]= st.empty()? -1: st.top();  
            // cout<<idx<<ans[idx]<<endl;
            st.push(nums[idx]); 
        }
        return ans; 
    }
};