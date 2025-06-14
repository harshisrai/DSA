/* Problem: Number_of_NGEs_to_the_right */

// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        vector<int> ans; 
        for(i: indices){
            int k=arr[i],l=0;
            for(int j=i+1;j<n; j++) if(arr[j]>k) l++;
            ans.push_back(l); 
        }
        return ans; 
    }
};