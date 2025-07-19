/* Problem: Connected_Components_Problem_in_Matrix */

// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int>& vis,vector<vector<int>> &adjLs){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it,vis,adjLs);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here
        vector<int> visited(v,0); 
        int ans = 0;
        vector<vector<int>> adjLs(v);
        
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (adj[i][j] == 1 && i != j) {
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