class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // start or end blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // single cell
        if (n == 1) return 1;

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        dist[0][0] = 1;
        q.push({1, {0, 0}});
        vis[0][0] = true;

        while (!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {

                    // skip the current cell
                    if (i == 0 && j == 0) continue;

                    int nrow = row + i;
                    int ncol = col + j;

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n &&
                        grid[nrow][ncol] == 0 && !vis[nrow][ncol] &&
                        dis + 1 < dist[nrow][ncol]) {

                        dist[nrow][ncol] = dis + 1;
                        vis[nrow][ncol] = true;

                        if (nrow == n - 1 && ncol == n - 1)
                            return dis + 1;

                        q.push({dis + 1, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};