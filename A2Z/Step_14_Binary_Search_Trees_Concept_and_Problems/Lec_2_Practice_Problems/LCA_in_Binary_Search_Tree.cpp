/* Problem: LCA_in_Binary_Search_Tree */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr; 
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left, p,q); 
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right, p,q); 
        return root;  //value lies in between or matches either p or q
    }
};