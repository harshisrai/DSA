/* Problem: Divide_two_integers_without_using_multiplication_division_and_mod_operator */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // overflow edge case

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long result = 0;

        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                result += 1LL << i;
                a -= b << i;
            }
        }

        // Determine the sign
        bool negative = (dividend < 0) ^ (divisor < 0);
        return negative ? -result : result;
    }
};
