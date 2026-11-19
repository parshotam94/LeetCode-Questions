/*
Not optimal


class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>&adj, int &cnt, vector<bool>&vis){
        vis[node]=true;
        for(auto [val, cost]: adj[node]){
            if(!vis[val]){
                cnt+=cost;
                dfs(val, adj, cnt, vis);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto e: edges){
            int u=e[0], v=e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            int cnt=0;
            vector<bool>vis(n, false);
            dfs(i, adj, cnt, vis);
            res.push_back(cnt);
        }
        return res;
    }
};

*/


class Solution {
public:
    void dfs1(int node, vector<vector<pair<int,int>>>& adj,
              vector<bool>& vis, int &cnt) {

        vis[node] = true;

        for(auto [val, cost] : adj[node]) {
            if(!vis[val]) {
                cnt += cost;
                dfs1(val, adj, vis, cnt);
            }
        }
    }

    void dfs2(int node, vector<vector<pair<int,int>>>& adj,
              vector<bool>& vis, vector<int>& ans) {

        vis[node] = true;

        for(auto [val, cost] : adj[node]) {
            if(!vis[val]) {

                if(cost == 0)
                    ans[val] = ans[node] + 1;
                else
                    ans[val] = ans[node] - 1;

                dfs2(val, adj, vis, ans);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0], v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> ans(n, 0);
        vector<bool> vis(n, false);

        int cnt = 0;
        dfs1(0, adj, vis, cnt);

        ans[0] = cnt;

        fill(vis.begin(), vis.end(), false);

        dfs2(0, adj, vis, ans);

        return ans;
    }
};
