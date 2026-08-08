class DSU{
vector<int>parent, rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    void Union(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DSU d(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || 
                stones[i][1]==stones[j][1]){
                    d.Union(i, j);
                }
            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(d.find(i)==i){
                components++;
            }
        }
        return n-components;
    }
};