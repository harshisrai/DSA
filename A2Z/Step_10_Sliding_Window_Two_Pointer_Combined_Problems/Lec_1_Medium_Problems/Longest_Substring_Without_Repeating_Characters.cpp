/* Problem: Longest_Substring_Without_Repeating_Characters */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0; 
        int len=0;
        int arr[128];
        for(int i=0; i<128; i++) arr[i]=-1; 
        while(r<s.size()){
            // cout<<"l"<<s[l];
            // cout<<"r"<<s[r]<<endl;
            int k=static_cast<int>(s[r]); 
            if(arr[k]!=-1 && arr[k]>=l){l=arr[k]+1;arr[k]=r;}
            else arr[k]=r; 
            len=max(r-l+1,len);
            r++;
        }
        return len;
    }
    /*
    Comment: 
    Two pointer approach where you if you get a repeated character, you move to the next index to the inital presence, update the new encounter and keep updating length until your last pointer reaches the end. 
    */
};