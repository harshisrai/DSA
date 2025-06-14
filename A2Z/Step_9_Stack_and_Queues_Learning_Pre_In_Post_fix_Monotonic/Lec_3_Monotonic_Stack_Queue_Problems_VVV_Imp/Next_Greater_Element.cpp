/* Problem: Next_Greater_Element */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int,int> mp; 
    stack<int> st; 
    for(int i=nums2.size()-1; i>=0; i--){
        if(st.empty()) mp[nums2[i]]=-1, st.push(nums2[i]); 
        else if(st.top()<nums2[i]){
            while(!st.empty() && st.top() <= nums2[i]) st.pop(); 
            mp[nums2[i]]=st.empty() ? -1 : st.top();
            st.push(nums2[i]); 
        }
        else{
            mp[nums2[i]]=st.top(); 
            st.push(nums2[i]);
        }
    }

    for(int i:nums1){
        ans.push_back(mp[i]); 
    }  
    return ans;  
    }
};