/* Problem: Implement_Lower_Bound */
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int l=0,r=arr.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]<=x){
                ans=mid; 
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
