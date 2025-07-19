/* Problem: Why_priority_Queue_is_used_in_Djisktra_s_Algorithm */


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto& edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        
        vector<int> dist(V,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second; 
            int dis=pq.top().first;
            // the below line is not compulsory, code will run without it too
            // just my obersvation that sometimes the same node gets pushed multiple times
            if (dis > dist[node]) continue; //skipping multiple entries with higher distance for the same node
            // that goes pushed in the priority queue during updates for the same node
            pq.pop(); // if something is poped, it's final distance is calculated from src
            for(auto& edge: adj[node]){
                int v=edge.first,w=edge.second;
                if(dis+w<dist[v]){
                    dist[v]=dis+w;
                    pq.push({dist[v],v});
                }
            }
            
        }
        return dist;
    }
};