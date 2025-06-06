/* Problem: Implement_Atoi */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s,long long res=0,bool fl=false, int sign=1) {
        int len=s.size(); 
        char ch=s[0];
        // cout<<ch<<": "<<ch-'0'<<";";
        // cout<<ch-'0'<<endl;

        if(fl==false){
            if(ch=='-') {sign=-1; fl=true;}
            else if(ch=='+') fl=true;
            else if(ch==' ');
            else if(ch-'9'>0 || ch-'0'<0) return res*sign; 
            else {fl=true; res=res*10+(ch-'0');}
        }
        else{
            if(ch-'9'>0 || ch-'0'<0) return res*sign; 
            else{
                res=res*10+(ch-'0');
                if(res>INT_MAX && sign==1) return INT_MAX;
                else if(res>(long long)INT_MAX+1 && sign==-1) return INT_MIN;
            }
        }

        // cout<<fl<<" "<<res<<endl;
        if(len==1) return res*sign;
        return myAtoi(s.substr(1),res,fl,sign);
    }
};