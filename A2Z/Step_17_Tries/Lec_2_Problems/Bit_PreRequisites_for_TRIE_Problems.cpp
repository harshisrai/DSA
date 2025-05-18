/* Problem: Bit_PreRequisites_for_TRIE_Problems */

class Solution {
  public:
    int XOR(int n, int m) {
        // code here
        return n^m;
    }

    int check(int a, int b) {
        return (b>>(a-1))&1;
        // code here
    }

        
    int setBit(int c, int d) {
        return d | (1<<(c));
        // code here
    }
};