/* Problem: Maximum_path_sum */

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
    int maxPathSum(TreeNode* root) {
        int m=-1100;
        sum(root,m); 
        return m;
    }
    int sum(TreeNode* root, int &m){
        if(root==NULL) return 0; 
        int ls=max(0,sum(root->left,m)); 
        int rs=max(0,sum(root->right,m));
        m=max(m, ls+rs+root->val);
        return root->val+max(ls,rs); 
    }
};