/* Problem: Number_of_Enclaves_flood_fill_implementation_multisource */

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(); 
        int n=grid[0].size();
        queue<pair<int,int>> q; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]==1) q.push({i,j}),grid[i][j]=0;;
                }
            }
        }

        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && ny >=0 && nx<m && ny<n){
                    if(grid[nx][ny]==1) q.push({nx,ny}), grid[nx][ny]=0;;
                }
            }
        }

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};