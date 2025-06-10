/* Problem: Number_of_substring_containing_all_three_characters */


class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={-1,-1,-1}; //min index track
        int l=0,r=0;
        int cnt=0,ans=0;
        while(r<s.size()){
            if(arr[s[r]-'a']==-1) arr[s[r]-'a']=r,cnt++;
            else arr[s[r]-'a']=r;
            if(cnt==3){
                l=min(arr[0],min(arr[1],arr[2]));
                l++;
                ans+=l;
                // cout<<r<<" "<<l<<endl;
            }
            r++;
        } 
        return ans;
        /*
        once you get count==3 -start keeping l at minm from there on
        */ 
    }
};