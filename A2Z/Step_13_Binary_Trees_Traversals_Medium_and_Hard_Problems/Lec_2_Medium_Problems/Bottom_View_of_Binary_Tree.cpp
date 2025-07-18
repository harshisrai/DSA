/* Problem: Bottom_View_of_Binary_Tree */

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> bottom; 
        queue<pair<Node*,int>>bfs; 
        vector<int> ans; 
        
        if(root==NULL) return ans; 
        bfs.push({root, 0}); 
        while(!bfs.empty()){
            auto it=bfs.front(); 
            bfs.pop(); 
            Node* node=it.first; 
            int line=it.second; 
            
            bottom[line]=node->data; //update always
            if(node->left) bfs.push({node->left,line-1});
            if(node->right) bfs.push({node->right,line+1});   
        }
        
        for(auto it: bottom) ans.push_back(it.second); 
        return ans;
    }
};