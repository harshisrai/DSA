/* Problem: Rotten_Oranges */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(); 
        int n=grid[0].size(); 
        int time=0, tot=0, cnt=0; 

        queue<pair<int,int>> rotten;

        //count the total oranges
        //get all the rotten oranges stored in queue
        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        
        //4 directional 
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        while(!rotten.empty()){
            int k=rotten.size(); 
            cnt+=k;
            //stage based rooting
            while(k--){
                int x=rotten.front().first, y=rotten.front().second; 
                rotten.pop(); 
                for(int i=0; i<4; i++){
                    int nx=x+dx[i], ny=y+dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty()) time++;
        }
        return tot==cnt? time:-1; 
    }
};