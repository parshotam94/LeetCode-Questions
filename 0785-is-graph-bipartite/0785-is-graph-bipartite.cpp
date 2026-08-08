class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size();

        // -1 = uncolored
        //  0 = color 0
        //  1 = color 1
        vector<int> color(V, -1);

        for (int start = 0; start < V; start++) {

            // Already processed component
            if (color[start] != -1)
                continue;

            queue<int> q;

            color[start] = 0;
            q.push(start);

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (int val : graph[node]) {

                    // Not colored yet
                    if (color[val] == -1) {

                        color[val] = 1 - color[node];
                        q.push(val);
                    }

                    // Already colored and has same color
                    else if (color[val] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};