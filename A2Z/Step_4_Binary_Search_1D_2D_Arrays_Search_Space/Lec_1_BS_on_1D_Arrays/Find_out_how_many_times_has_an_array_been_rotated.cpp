/* Problem: Find_out_how_many_times_has_an_array_been_rotated */

#include<bits/stdc++.h>
using namespace std;
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ans=INT_MAX;
        int idx;
        //to get Kth rotation - I need minm; 
        int l=0,r=arr.size()-1; 
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[l]<=arr[r]){
                idx=(ans>arr[l])?l:idx; 
                ans=min(ans,arr[l]);
                return idx;
            }
            if(arr[l]<=arr[mid]){
                idx=(ans>arr[mid])?mid:idx; 
                ans=min(ans,arr[mid]);
                l=mid+1;
            }
            else if(arr[mid]<=arr[r]){
                idx=(ans>arr[mid])?mid:idx; 
                ans=min(ans,arr[mid]);
                r=mid-1;
            }
            // cout<<ans<<endl;
        }
        return -1;
    }
};