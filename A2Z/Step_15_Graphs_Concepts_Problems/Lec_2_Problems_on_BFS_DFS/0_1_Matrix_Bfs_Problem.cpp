/* Problem: 0_1_Matrix_Bfs_Problem */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        queue<pair<int,int>> q; 
        // bfs - gives you shorted distance from where you start
        // so if we start from what needs to be nearest (here zero), we can assign the shortest value possible

        // it seems perfectly sensible to start from all the zeroes in the matrix so that we can give
        // the shortest distance to all the ones in the matrix from the zeroes
        // thus we will do multi-source BFS
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) q.push({i,j}),vis[i][j]=0;
            }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        while(!q.empty()){
            auto[x,y]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n){
                    if(vis[nx][ny]==-1) vis[nx][ny]=1+vis[x][y], q.push({nx,ny});
                }
            }
        }
        return vis;
    }
};