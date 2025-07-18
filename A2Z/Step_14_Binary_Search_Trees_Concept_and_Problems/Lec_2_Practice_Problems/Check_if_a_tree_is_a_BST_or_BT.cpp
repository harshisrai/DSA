/* Problem: Check_if_a_tree_is_a_BST_or_BT */

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
private:
    bool validate(TreeNode* Node, long max, long min){
        if(!Node) return true;
        if(Node->val>=max || Node->val<=min) return false; 
        return validate(Node->left, Node->val, min) && validate(Node->right,max,Node->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MAX, LONG_MIN); 
    }
};