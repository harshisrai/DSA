/* Problem: Check_Palindrome */


class Solution {
public:
    int reverse(int x) {
        long long y,z=0; 
        int ans=0; 
        bool neg=false; 
        y=x; 
        if(y<0) neg=true, y=-y; 
        else if(y==0) return 0; 
        while(y>0){
            int i=y%10;
            y=y/10;
            z=z*10+i;
        }
        z= neg?-z:z;         
        if(z>INT_MAX|| z<INT_MIN) ans=0;
        else ans=z; 
        return ans; 
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        else if (x==0) return true;  
        int y=reverse(x); 
        if(y!=x) return false;
        return true; 
    }
};

/*
In order to check if a number is a palindrome, 
we can't do like strings, that O(n/2) time complexity is enough,
We will have to reverse the number and then compare it with the original number.
This will take O(n) time complexity, where n is the number of digits in the number.
The space complexity is O(1) as we are not using any extra space.
*/