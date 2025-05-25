/* Problem: Implement_TRIE_INSERT_SEARCH_STARTSWITH */
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;
    Node(){
        for(auto &link:links) link=nullptr;
    }

    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }

    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true; 
    }

    bool isEnd(){
        return flag;
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
            for(char ch:word){
                if(!node->containsKey(ch)){
                    node->put(ch, new Node());
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

        bool startsWith(string prefix){
            Node* node = root;
            for(char ch:prefix){
                if(node->containsKey(ch)){
                    node=node->get(ch);
                } 
                else return false;   
            }
            return true;
        }
};

int main(){
    Trie trie;
    trie.insert("harsh");
    trie.insert("hard");
    trie.insert("hammer");
    cout<<trie.search("ha")<<endl;
    cout<<trie.startsWith("ha")<<endl;
    cout<<trie.search("hammer")<<endl;
    cout<<trie.search("harder")<<endl;

    return 0;
}