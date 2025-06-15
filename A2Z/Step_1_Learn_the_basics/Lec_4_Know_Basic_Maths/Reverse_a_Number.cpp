/* Problem: Reverse_a_Number */

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
};