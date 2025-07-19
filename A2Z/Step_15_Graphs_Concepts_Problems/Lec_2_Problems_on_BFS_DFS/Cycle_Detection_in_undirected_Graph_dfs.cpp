/* Problem: Cycle_Detection_in_undirected_Graph_dfs */

/*
Good question, specially how DFS needs to return the result to the top level 
after doing it's recursion. 
*/
class Solution {
  public:
        bool dfs(int node, int parent, int vis[], vector<vector<int>>& adj) {
        vis[node] = 1; 
        // visit adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // unvisited adjacent node
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj))return true; 
            }
            // visited node but not a parent node
            else if(adjacentNode != parent) return true; 
        }
        return false; 
    }
    
    bool detect(int src, vector<vector<int>>& adj, int vis[]) {
      vis[src] = 1; 
      // store <source node, parent node>
      queue<pair<int,int>> q; 
      q.push({src, -1}); 
      // traverse until queue is not empty
      while(!q.empty()) {
          int node = q.front().first; 
          int parent = q.front().second; 
          q.pop(); 
          
          // go to all adjacent nodes
          for(auto adjacentNode: adj[node]) {
              // if adjacent node is unvisited
              if(!vis[adjacentNode]) {
                  vis[adjacentNode] = 1; 
                  q.push({adjacentNode, node}); 
              }
              // if adjacent node is visited and is not it's own parent node
              else if(parent != adjacentNode) {
                  // yes it is a cycle
                  return true; 
              }
          }
      }
      // there's no cycle
      return false; 
  }
  public:
    // Function to detect cycle in an undirected graph.
     bool isCycleDFS(int V, vector<vector<int>>& adj) {
       int vis[V] = {0}; 
       // for graph with connected components 
       for(int i = 0;i<V;i++) {
           if(!vis[i]) {
               if(dfs(i, -1, vis, adj)) return true; 
           }
       }
       return false; 
    }
    
     bool isCycleBFS(int V, vector<vector<int>>& adj) {
        // initialise them as unvisited 
        int vis[V] = {0};
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                if(detect(i, adj, vis)) return true; 
            }
        }
        return false; 
    }

    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //edges to adjList
        vector<vector<int>> adj(V);
        for(auto & edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        return isCycleDFS(V, adj);
        // return isCycleBFS(V, adj);
    }
};