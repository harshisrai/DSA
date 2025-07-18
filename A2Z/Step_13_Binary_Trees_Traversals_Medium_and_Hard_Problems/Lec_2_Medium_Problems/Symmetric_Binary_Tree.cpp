/* Problem: Symmetric_Binary_Tree */

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
    bool check(TreeNode* n, TreeNode* m){
        if(n && m){
            if(n->val!=m->val) return false; 
            return check(n->left,m->right) && check(n->right,m->left);
        }
        else if(n||m) return false;
        else return true; 
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true; 
        return check(root->left, root->right); 
    }   
};