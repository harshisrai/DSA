/* Problem: Top_View_of_Binary_Tree */

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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans; 
       
        
        map<int, int> top; // map to store top view poistions
        queue<pair<Node*, int>>bfs; //bfs for node & vertical poistion
        
        bfs.push({root, 0});
         
        if(root==NULL){
            return ans;
        }
        
        while(!bfs.empty()){
            auto it=bfs.front(); 
            bfs.pop(); 
            Node* node= it.first; 
            int line=it.second; 
            
            if(top.find(line)==top.end()){
                //update only when not exists before
                top[line]=node->data; 
            }
            
            if(node->left!=NULL) bfs.push({node->left,line-1}); 
            if(node->right!=NULL) bfs.push({node->right,line+1});
            
        }
        
        for(auto it: top){
            ans.push_back(it.second); 
        }
        
        return ans; 
    }
};