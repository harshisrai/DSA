/* Problem: Bipartite_Graph_DFS */

class Solution {
public:
    bool dfs(int node, int c,vector<vector<int>>& graph, vector<int>& color){
        color[node]=c;
        for(auto it:graph[node]){
            if(color[it]==-1){
                if(!dfs(it, !c,graph,color)) return false;
            }
            else{
                if(color[it]==c)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        int c=0;
        for(int i=0;i<v;i++){
           if(color[i]==-1) if(!dfs(i,c,graph,color)) return false;
        }
        return true;
    }
};