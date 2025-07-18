/* Problem: Vertical_Order_Traversal_of_Binary_Tree */

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> nodes; // vertical level info map
        queue<pair<TreeNode*, pair<int,int>>> bfs; // queue for BFS - each pair is Node & Coordinate

        bfs.push({root, {0, 0}});

        //bfs 
        while(!bfs.empty()){
            auto p = bfs.front(); 
            bfs.pop(); 
            TreeNode* temp = p.first;

            int x= p.second.first;
            int y= p.second.second; 

            nodes[x][y].insert(temp->val);

            if(temp->left) bfs.push({temp->left,{x-1,y+1}}); 
            if(temp->right) bfs.push({temp->right,{x+1,y+1}}); 
        }

        vector<vector<int>> ans; 
        for(auto p:nodes){
            // get every x
            vector<int> col; 
            for(auto q: p.second){
                //insert every y -> mutliset for any (x,y) because of overlap possible - multiset stores sorted.
                col.insert(col.end(), q.second.begin(), q.second.end()); 
            }
            ans.push_back(col); 
        }
        return ans;                
    }
};