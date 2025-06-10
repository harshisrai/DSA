/* Problem: longest_repeating_character_replacement */


class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0; 
        int maxCount=0;
        int arr[26] = {0}; //short hand initalization ninja tehcniquw
        while(r<s.size()){
            arr[s[r]-'A']++;
            maxCount=max(maxCount,arr[s[r]-'A']);

            while(maxCount+k<r-l+1){
                //the condition of loop is as such that - everty time 
                // we only look over the largest window possible thus r-l will return the ans
                // irrespective of whether actual length is less or more than maxCount+k
                arr[s[l]-'A']--;
                l++;
            }
            r++;
        } 
        // return (maxCount+k>s.size())? s.size():maxCount+k;
        return r-l;

    }
};