/* Problem: Sort_Characters_by_frequency */
#include<bits/stdc++.h>
using namespace std;    

bool comp(int a, int b) {
  	return a > b;
    }
class Solution {
public:
    string frequencySort(string s) {
        int arr[62];
        string ans="";
        for(char ch:s){
            int idx;
            if(ch>='0' && ch<='9') arr[ch-'0']++;
            else if(ch>='a') arr[36+ch-'a']++;
            else arr[10+ch-'A']++;
            // cout<<ch<<endl;
        }  
        for(int i=0;i<62;i++){
            if(i<=9) arr[i]=arr[i]*1000+'0'+i;
            else if(i<=35) arr[i]=arr[i]*1000+'A'+i-10;
            else arr[i]=arr[i]*1000+'a'+i-36;
            // cout<<arr[i]<<endl;
        }
        sort(arr, arr+62,comp); //sorting an array directly using sort() (syntax slightly differs from vector)
        for(int i:arr){
            // cout<<i<<endl;
            if(i>1000){
                int asc=i%1000;
                int rep=i/1000;
                // cout<<asc<<" "<<rep<<endl;
                while(rep>0){
                    ans.push_back(static_cast<char>(asc));
                    rep--;
                }
            }
            else break;
        }
        return ans;
    }
};