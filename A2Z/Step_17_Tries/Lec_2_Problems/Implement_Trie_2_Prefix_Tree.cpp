/* Problem: Implement_Trie_2_Prefix_Tree */

#include <bits/stdc++.h> 
using namespace std; 
struct Node{
    Node* links[26];
    int flag=0;
    int cp=0;
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
        flag+=1; 
    }

    int isEnd(){
        return flag;
    }
};

class Trie{
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
                node->cp+=1;
            }
        node->setEnd();
    }


    int countWordsEqualTo(string &word){
        Node* node=root;
            for(int i=0; i<word.length(); i++){
                if(!node->containsKey(word[i])){
                    return 0;
                }
                node = node->get(word[i]); 
            }
        return node->isEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(char ch:word){
            if(node->containsKey(ch)){
                node=node->get(ch);       
            } 
            else return 0;   
        }
        return node->cp;
    }

    void erase(string &word){
        Node* node=root;
        if(countWordsEqualTo(word)>=1){
            for(char &ch:word){
                node=node->get(ch);
                node->cp-=1;
            }   
        node->flag-=1;
        }
    }
};
