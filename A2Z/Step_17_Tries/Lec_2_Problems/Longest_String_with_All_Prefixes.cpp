/* Problem: Longest_String_with_All_Prefixes */

#include<bits/stdc++.h>
using namespace std; 

struct Node{
    Node* links[26];
    bool flag=false; 
    Node() {            // ← add this!
    for(int i=0;i<26;i++) links[i]=nullptr;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag; 
    }
    bool containsKey(char ch){
        return links[ch-'a']; 
    }
    void put(char ch){
        Node* node=new Node(); 
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    private: 
        Node* root;
    public: 
        Trie(){
            root=new Node(); 
        }

        void insert(string word){
            Node* node=root; 
            for(char ch:word ){
                if(!(node->containsKey(ch))){
                    node->put(ch); 
                }
                node=node->get(ch); 
            }
            node->setEnd();
        }

        bool search(string word){
            Node* node=root;
            for(int i=0; i<word.length(); i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node = node->get(word[i]); 
            }
            return node->isEnd();
        }

        bool checkAllPrefix(string prefix){
            Node* node = root;
            for(char ch:prefix){
                if(node->containsKey(ch)){
                    node=node->get(ch);
                    if(!(node->isEnd())){return false;}
                } 
                else return false;   
            }
            return true;
        }

}; 

string completeString(int n, vector<string> &a){
    Trie trie; 
    // first populate trie 
    for(auto &it:a){
        // cout<<"insert "<<it<<endl; 
        trie.insert(it);  
    }
    
    // look for the longest & left sided (lexiographically smallest) complete string
    string longest=""; 
    for(auto &it:a){
        // cout<<"outside"<<it<<endl;
        if(trie.checkAllPrefix(it)){
            // cout<<"inside"<<it<<endl; 
            if(it.size()>longest.size()) longest=it; 
            if(it.size()==longest.size() && it<longest) longest=it;
        }
    }
    return (longest=="")?"None":longest; 
}

int main(){
    vector<string> s={"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout<<completeString(6,s);
    return 0; 
}
