/* Problem: Flood_fill */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(); 
        int n=image[0].size(); 
        int initialColor = image[sr][sc];
        if (initialColor == color) return image; //if same
        queue<pair<int,int>> flood; 
        flood.push({sr,sc});
        image[sr][sc] = color;

        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        while(!flood.empty()){
            int x=flood.front().first, y=flood.front().second;
            flood.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny]==initialColor) image[nx][ny]=color,flood.push({nx,ny}); 
            }
        }

        return image;
    }
};