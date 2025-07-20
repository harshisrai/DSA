/* Problem: Post_order_Traversal_of_Binary_Tree */

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postorder(root, arr);
        return arr;
    }
    void postorder(TreeNode* root, vector<int> &arr){
    if(root == nullptr){
        return;
    }
    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->val);
}
    
};