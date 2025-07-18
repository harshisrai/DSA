/* Problem: Delete_a_Node_in_Binary_Search_Tree */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr; 
        if(root->val<key) root->right=deleteNode(root->right, key); 
        else if(root->val>key)  root->left=deleteNode(root->left, key); 
        else{
            // if matches
            if(!root->left && !root->right){delete root; return nullptr;} //leaf
            if(!root->left){ //only right child
                TreeNode* temp=root->right; 
                delete root; 
                return temp; 
            }
            if(!root->right){ //only left child
                TreeNode* temp=root->left; 
                delete root; 
                return temp; 
            }
            
            //if both child - either right successor (leftmost in right subtree) or left predecessor (rightmost in left subtree)
            TreeNode* succ=root->right; //successor logic used here
            while(succ->left) succ=succ->left; 
            root->val=succ->val; 
            root->right= deleteNode(root->right, succ->val); // Delete successor
        }
        return root; 
    }
};
