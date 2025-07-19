/* Problem: Topo_Sort */

class Solution {
  public:
    void dfs(int node, stack<int>& st, vector<int>& vis, vector<vector<int>>&adjLs){
        vis[node]=1; 
        for(auto it:adjLs[node]){
            if(!vis[it]) dfs(it, st, vis, adjLs); 
        }
        st.push(node);   // the essence of topological sort is here
        //this is where we are getting the order (later to be reversed)
    } 
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjLs(V); 
        for(auto&edge: edges){
            int u=edge[0], v=edge[1]; 
            adjLs[u].push_back(v); 
        }
        
        vector<int> vis(V,0);
        stack<int>st; 
        
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, st,vis, adjLs);
        }
        
        vector<int> ans; 
        // The stack stores nodes in reverse topological order:
        // nodes that come later in the process are on top.
        // We pop to reverse the order and get the correct topological sort,
        // where each node appears before any node that depends on it.
        while(!st.empty()){ans.push_back(st.top());st.pop();}
        return ans;
    }
};