/* Problem: Count_the_number_of_set_bits */

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        int total = 0;
        while (n > 0) {
            int x = log2(n);                // highest power of 2 ≤ n
            int pow2x = 1 << x;             // 2^x
            int bitsTill2PowX = x * (1 << (x - 1));
            int msb2n = n - pow2x + 1;
            
            total += bitsTill2PowX + msb2n;
    
            n = n - pow2x;                  // shrink n and repeat
        }
        return total;
    }
};

/* My Note:  
It's basically a recursive formula that first counts total set bits from 1 to closest power of 2 in one go and
the left of recursion cycles are for remaining numbers greater than that power of 2. - we shrink n and repeat */