class Solution {
public:
    int cnt=0;
    void dfs(int node, vector<vector<pair<int, int>>>&adj, vector<bool>&vis){
        vis[node]=true;
        for(auto [val, cost]: adj[node]){
            if(!vis[val]){
                cnt+=cost;
                dfs(val, adj, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto e: connections){
            int u=e[0], v=e[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        vector<bool>vis(n, false);
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(0, adj, vis);
        }
        return cnt;
    }
};