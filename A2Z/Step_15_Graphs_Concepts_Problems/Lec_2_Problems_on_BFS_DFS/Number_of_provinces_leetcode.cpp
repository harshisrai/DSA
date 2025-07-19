/* Problem: Number_of_provinces_leetcode */

class Solution {
private: 
    void dfs(int node, vector<int>& vis,vector<vector<int>> &adjLs){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it,vis,adjLs);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int ans = 0;
        vector<int> visited(v,0);
        vector<vector<int>> adjLs(v); // Create an empty adjacency list

        // Construct the adjacency list from the isConnected matrix
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); // Undirected graph
                }
            }
        }

        for(int i =0;i<v;i++){
            if(visited[i]==0){
                dfs(i,visited,adjLs);
                ans+=1;
            }
        }
        return ans;
    }
};
