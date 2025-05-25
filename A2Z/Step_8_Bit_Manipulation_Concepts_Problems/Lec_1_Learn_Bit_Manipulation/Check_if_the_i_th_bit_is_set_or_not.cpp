/* Problem: Check_if_the_i_th_bit_is_set_or_not */

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        return (n>>k)&1;
    }
};