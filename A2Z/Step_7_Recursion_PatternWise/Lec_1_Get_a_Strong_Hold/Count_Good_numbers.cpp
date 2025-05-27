/* Problem: Count_Good_numbers */

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenPart = modPow(5, even);
        long long oddPart = modPow(4, odd);

        return (evenPart * oddPart) % MOD;
    }
};

/*My note: 
Though it becomes a direct, formula - trying to calculate it is problematic because
a) lots of format start to clash - pow has result in double & you can use modulo onto it, if you typecast in long long
then it will go out of range for x^n, where n=50 -> Made GPT try a lot, but you simply can't use pow for this problem due to data type trouble.
b) The only way out: to avoid getting into data type trouble, you use binary exponentiation with MOD, to avoid both overflowing &
data type trouble of double & long long by doing whole work in long that allows arithmetic operations onto it.*/