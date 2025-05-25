/* Problem: Check_if_a_number_is_power_of_2_or_not */

class Solution {
public:
    bool isPowerOfTwo(int n) {
    if(n==0) return false;
    while(n%2==0){
        n/=2;
    }
    if(n==1) return true;
    else return false;
    }
};