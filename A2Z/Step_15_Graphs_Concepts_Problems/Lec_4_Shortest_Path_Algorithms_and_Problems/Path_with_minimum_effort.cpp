/* Problem: Path_with_minimum_effort */


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9)); //keep tracks of minm diff path (diff is max abs diff that occur in that path)
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

         while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first; //diff is identity of a path - max abs diff corresponding to the path
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == m - 1)
                return diff; //ans which is minm effort path (this diff is maxm abs difference within that path)
           
            for (int i = 0; i < 4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff); //max abs diff in path
                    if (newEffort < dist[newr][newc]) //storing minm effort to a point in dist
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }
};


