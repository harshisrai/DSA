/* Problem: Number_of_Distinct_Substrings_in_a_String */

#include<bits\stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag; 

    void put(char ch){
        Node* node=new Node();
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a']; 
    }
    bool containsKey(char ch){
        return links[ch-'a'];
    }
}; 

int countDistinctSubstrings(string &s)
{
    int cnt=0;

    Node* root=new Node(); 
    //    Write your code here.
    for(int i=0; i<s.size(); i++){
        Node* node=root;
        for(int j=i; j<s.size(); j++){
            if(!(node->containsKey(s[j]))){
                node->put(s[j]);
                cnt++;
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1; 
}

int main(){
    string st="aba";
    cout<<countDistinctSubstrings(st);
}