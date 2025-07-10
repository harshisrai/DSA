/* Problem: Check_if_the_Binary_tree_is_height_balanced_or_not */

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
    bool isBalanced(TreeNode* root) {
        return balance(root)!=-1;
    }
    int balance(TreeNode* root){
        if(root==NULL) return 0; 

        int lh=balance(root->left); 
        if(lh==-1) return -1; 
        int rh=balance(root->right); 
        if(rh==-1) return -1; 

        //current node balanced or not
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
};