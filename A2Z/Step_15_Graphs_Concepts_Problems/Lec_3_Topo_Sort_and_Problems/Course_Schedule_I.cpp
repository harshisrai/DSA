/* Problem: Course_Schedule_I */

class Solution {
public:
    bool dfs(int node, vector<int>& inRecursion, vector<int>& vis, vector<vector<int>>&adjLs){
        vis[node]=1; 
        inRecursion[node]=1; 
        for(auto it:adjLs[node]){
            if(!vis[it]){ if(!dfs(it, inRecursion, vis, adjLs)) return false;} 
            else if(inRecursion[it]) return false;  
            //tracks whether in recursion or not already, if yes then we are again at a node which 
            //was up in this path. 
        }
        inRecursion[node]=0;
        return true;
    } 
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjLs(V); 
        for(auto& edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            adjLs[v].push_back(u); 
        }
    
        vector<int> inRecursion(V,0);
        vector<int> vis(V,0);    
        for(int i=0; i<V; i++){
            if(!vis[i]) {if(!dfs(i,inRecursion,vis, adjLs)) return false;}
        }
        return true;
        }
};