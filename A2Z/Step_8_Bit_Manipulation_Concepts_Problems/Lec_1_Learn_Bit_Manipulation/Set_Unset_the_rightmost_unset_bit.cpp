/* Problem: Set_Unset_the_rightmost_unset_bit */

class Solution {
  public:
    int setBit(int num) {
        // Write Your Code here
    int k=1,n=num;
    while(n>0){
        if(n%2==0) break;
        else {n/=2; k<<=1;}
    }
    return num=num|k;
    }
};