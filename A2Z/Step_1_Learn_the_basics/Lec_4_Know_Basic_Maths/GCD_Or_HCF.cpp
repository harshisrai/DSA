/* Problem: GCD_&_LCM */


class Solution {
  public:
    int lcm(int x,int y){
        if(x>y){
            int z=x,i=2;
            while(z%y!=0) z=x*i,i++;
            return z; 
        }
        else if(x<y){
            int z=y,i=2;
            while(z%x!=0) z=y*i,i++;
            return z;
        }
        else return x; 
    }
    
    int gcd(int x,int y){
        while(y%x!=0){
            int z=x; 
            x=y%x;
            y=z; 
        }
        return x;
    }
    
  
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        return {lcm(a,b),gcd(a,b)};
    }
};