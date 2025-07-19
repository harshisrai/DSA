/* Problem: Kahn_s_Algorithm */

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V); 
        for(auto&edge: edges){
            int u=edge[0], v=edge[1]; 
            adj[u].push_back(v); 
        }
        // the whole essence of Kahn's algorithm is here - indegree calculation
        int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {indegree[it]++;}
		}

        queue<int> q; 
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo; 
        while(!q.empty()){
            int node=q.front(); 
            q.pop();
            topo.push_back(node); 
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo;
    }
};