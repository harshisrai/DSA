/* Problem: Reverse_an_array */

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        // reverse(arr.begin(), arr.end()); 
        int len=arr.size(); 
        int i=0;
        while(i<len/2){
            swap(arr[i],arr[len-i-1]);
            i++;
        }
    }
};