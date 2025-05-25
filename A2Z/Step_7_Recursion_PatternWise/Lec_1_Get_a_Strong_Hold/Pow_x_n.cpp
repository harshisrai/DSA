/* Problem: Pow_x_n */

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;          // promote to avoid overflow when n = INT_MIN
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        
        double result = 1.0;
        while (N > 0) {
            if (N & 1)              // if the current bit is 1
                result *= x;
            x *= x;                 // square the base
            N >>= 1;                // shift off the bit we just used
        }
        return result;
    }
};