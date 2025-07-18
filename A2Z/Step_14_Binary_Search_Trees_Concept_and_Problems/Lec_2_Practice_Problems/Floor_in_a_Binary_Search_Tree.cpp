/* Problem: Floor_in_a_Binary_Search_Tree */

// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int ans=-1; 
        while(root){
            if(root->data==x) return x; 
            else if(root->data>x){
                root=root->left; 
            }
            else{
                ans=root->data; 
                root=root->right; 
            }
        }
        return ans;
    }
};