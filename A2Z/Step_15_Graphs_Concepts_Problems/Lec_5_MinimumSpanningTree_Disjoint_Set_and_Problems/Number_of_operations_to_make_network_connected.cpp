/* Problem: Number_of_operations_to_make_network_connected */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class DisjointSet {
        vector<int> rank, parent;
    public:
        int extra=0,comp=-1,n;
        DisjointSet(int n) {
            this->n=n;
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
            if (ulp_u == ulp_v) extra++;
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

        void components(){
            for (int i = 1; i <= n; i++) {
                if(parent[i] == i){
                    comp++;
                }
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
    DisjointSet ds(n);
    for (vector<int> c: connections){
        int a=c[0];
        int b=c[1];
        ds.unionByRank(a+1,b+1);
    }

    ds.components();
    if(ds.comp<=ds.extra){
        return ds.comp;
    }
    else{
        return -1;
    }

    }
};