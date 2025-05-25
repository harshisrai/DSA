/* Problem: Introduction_to_Bit_Manipulation_Theory */

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bitManipulation(int num, int i) {
        cout<<((num>>(i-1))&1)<<" ";
        cout<<(num|1<<(i-1))<<" ";
        if((num>>(i-1))&1){
            cout<<num-(1<<(i-1));
        }
        else cout<<num;
        
    }
};