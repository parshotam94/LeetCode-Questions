class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);   // reversed graph
        vector<int> indegree(n, 0);

        // Build reversed graph
        for (int i = 0; i < n; i++) {
            for (int v : graph[i]) {
                adj[v].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        // Terminal nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int val : adj[node]) {
                indegree[val]--;

                if (indegree[val] == 0) {
                    q.push(val);
                }
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};