/* Problem: Longest_Substring_with_At_Most_K_Distinct_Characters */

// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        int l=0,r=0,cnt=0,maxLen=-1; 
        int arr[26]={0}; 
        
        while(r<s.size()){
            if(arr[s[r]-'a']==0) cnt++;
            arr[s[r]-'a']++;
            
            if(cnt>k){
                if(arr[s[l]-'a']==1) cnt--;
                arr[s[l]-'a']--;
                l++;
            }
            
            /*
            if(cnt>k){
                if(arr[s[l]-'a']==1) cnt--;
                arr[s[l]-'a']--;
                l++;
            }
            
            could even be 
            
            while(cnt>k){
                if(arr[s[l]-'a']==1) cnt--;
                arr[s[l]-'a']--;
                l++;
            }
            
            but the draw back was that you were decresing the window size aggresively 
            to maintain a valid one. 
            
            The point is that why should we look for windows smaller than the max which
            we have already seen. The if approach ensures that we only look for valid
            windows which are equal or greater than the window we have already seen.
            
            */
            
            if(cnt==k) maxLen=max(maxLen, r-l+1); 
            r++;
        }
        return maxLen;
    }
};
