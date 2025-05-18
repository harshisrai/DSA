/* 
Problem: Most_stones_removed_with_same_rows_or_columns
https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 */

#include<bits/stdc++.h>
using namespace std;

/*
Edge case/Constraint which caused error initally: 

1 <= stones.length <= 1000
0 <= xi, yi <= 10^4

In the question there wasn't any idea given of the matrix size on which stones are being placed. 
So I made a matrix n*n roughly, n being the size of stones placed;

These constraints made it interesting: 
You can have stone coordinates more than that captured in n*n, it means they aren't necessarily
interested in placing near origin or starting from origin in 1st quadrant.

*/

class Solution {
public:
    class DisjointSet {
    public:
        vector<int> rank, parent;
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
    
        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }
    
        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    };

    
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);

        for(auto ls: stones){
            int r=ls[0];
            int c=ls[1];
            ds.unionByRank(r,c+maxRow+1);
        }

        int validComponent=0; 

        for(int i=0;i<maxRow + maxCol + 2;i++){
            if(ds.parent[i]==i && ds.rank[i]!=0){
                validComponent+=1;
            }
        }
        return stones.size()-validComponent;   
    }
};

