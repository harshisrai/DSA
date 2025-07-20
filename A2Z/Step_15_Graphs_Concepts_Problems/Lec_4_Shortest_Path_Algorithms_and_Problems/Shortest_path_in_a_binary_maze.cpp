/* Problem: Shortest_path_in_a_binary_maze */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(); 
        vector<vector<int>> dis(n,vector<int>(n,-1));
        queue<pair<int,int>> q; 
        if(grid[0][0]==0) q.push({0,0}), dis[0][0]=1;
        int dx[8]={1,1,-1,-1,0,0,1,-1};
        int dy[8]={1,-1,1,-1,1,-1,0,0};
        while(!q.empty()){
            auto[x,y]=q.front();q.pop();
            for(int i=0;i<8;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n ){
                    if(dis[nx][ny]==-1 && grid[nx][ny]==0) dis[nx][ny]=dis[x][y]+1, q.push({nx,ny});
                }
            }
        }
        return dis[n-1][n-1];
    }
};