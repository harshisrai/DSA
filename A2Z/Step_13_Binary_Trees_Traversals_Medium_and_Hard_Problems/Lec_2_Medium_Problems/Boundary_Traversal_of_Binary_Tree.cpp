/* Problem: Boundary_Traversal_of_Binary_Tree */

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private: 
    bool isLeaf(Node* root){
        return !root->left && !root->right; 
    }
    
    void addLeft(Node* node, vector<int>& res){
        vector<int> temp; 
        while(node){
            if(!isLeaf(node)) res.push_back(node->data); 
            if(node->left){node=node->left;}
            else node=node->right; 
        }
    }
    void addLeaves(Node* node, vector<int>& res){
       if(isLeaf(node)){
           res.push_back(node->data); 
           return; 
       }
       if(node->left)  addLeaves(node->left, res);
       if(node->right)  addLeaves(node->right, res);
    }
    void addRight(Node* node, vector<int>& res){
        vector<int> temp; 
        while(node){
            if(!isLeaf(node)) temp.push_back(node->data); 
            if(node->right){node=node->right;}
            else node=node->left; 
        }
        //adding in reverse order -> bottom-up
        for(int i=temp.size()-1; i>=0; --i) res.push_back(temp[i]);
    }
    
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> res; 
        if(!root)return res; 
        if(!isLeaf(root)){
            res.push_back(root->data); 
        }
        addLeft(root->left,res); 
        addLeaves(root,res);
        addRight(root->right,res); 
        return res; 
        
    }
};