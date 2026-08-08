class Solution {
public:
    void dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 ||
            row >= n || col >= m ||
            vis[row][col] ||
            grid[row][col] == 0) {
            return;
        }

        vis[row][col] = true;

        dfs(row + 1, col, grid, vis);
        dfs(row - 1, col, grid, vis);
        dfs(row, col + 1, grid, vis);
        dfs(row, col - 1, grid, vis);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(
            n, vector<bool>(m, false)
        );

        // First and last columns
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, grid, vis);

            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(i, m - 1, grid, vis);
        }

        // First and last rows
        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, grid, vis);

            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(n - 1, j, grid, vis);
        }

        // Count land cells that were NOT reachable
        // from the boundary
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }

        return cnt;
    }
};