/* Problem: check_whether_one_string_is_a_rotation_of_another */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length()==goal.length() && (s+s).find(goal)!=string::npos;
        //string::npos is a pre defined constant (note - simply npos will give error)
        //means - no position/ invalid position 
    }
};