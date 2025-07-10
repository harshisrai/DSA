/* Problem: Diameter_of_Binary_Tree */

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0; 
        // height(root, diameter); 
        auto[d,h]=height2(root); 
        // return diameter; 
        return d;
    }
private: 
    int height(TreeNode* node, int& diameter){
        if(!node) return 0; 
        int lh=height(node->left, diameter); 
        int rh=height(node->right, diameter); 
        diameter=max(diameter, lh+rh); 
        return 1+max(lh,rh); 
    }

    pair<int,int> height2(TreeNode* node){
        if(node==NULL) return {0,0};
        auto [d1,lh]=height2(node->left); 
        auto [d2,rh]=height2(node->right); 
        int d=max(d1,d2); 
        d= max(d,lh+rh);
        int h=max(lh,rh)+1;
        return {d,h}; 
    }
};