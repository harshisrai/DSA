/* Problem: Valid_Paranthesis_Checker */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; // both are count of (

        for (char ch : s) {
            if (ch == '(') {
                low++; high++;
            } else if (ch == ')') {
                low--; high--;
            } else { // '*'
                low--; high++;
            }
            if (high < 0) return false;
            if (low < 0) low = 0;
        }

        return low == 0;
    }

    /*The idea is to ensure that it works for the extreme cases - * as ( and ) - if yes then return true */
};