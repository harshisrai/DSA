/* Problem: Armstrong_Numbers */

// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int temp=n,len=0;
        while(n>0) n=n/10,len++;
        int sum=0; 
        n=temp;
        for(int i=0; i<len; i++){
            sum+=pow(n%10,len); 
            n=n/10;
        }
        return sum==temp;
    }
};