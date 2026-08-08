class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU d(n);
        int components=n;
        int extras=0;

        for(auto &it: connections){
            if(d.find(it[0])==d.find(it[1])){
                extras++;
            }
            else{
                d.Union(it[0], it[1]);
                components--;
            }
        }
        int req=components-1;
        if(extras>=req){
            return req;
        }
        return -1;
    }
};