/*
class Solution {
public:
    int ans=0;
    void dfs(int row, int col, int &cnt, vector<vector<bool>>&vis, vector<vector<int>>&grid){
        int n=grid.size(), m=grid[0].size();
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==0 || vis[row][col]==true) return;
        vis[row][col]=true;
        cnt++;
        dfs(row+1, col, cnt, vis, grid);
        dfs(row-1, col, cnt, vis, grid);
        dfs(row, col+1, cnt, vis, grid);
        dfs(row, col-1, cnt, vis, grid);
    }
    int largestIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(), false));
                int cnt=0;
                if(grid[i][j]==0){
                    grid[i][j]=1;
                    dfs(i, j, cnt, vis, grid);
                    grid[i][j]=0;
                }
                else{
                    dfs(i, j, cnt, vis, grid);
                }
                ans=max(ans, cnt);
            }
        }
        return ans;
    }
};

*/

class Solution {
public:
    int dfs(int row, int col, int id,
            vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m ||
            grid[row][col] != 1)
            return 0;

        grid[row][col] = id;

        int cnt = 1;

        cnt += dfs(row + 1, col, id, grid);
        cnt += dfs(row - 1, col, id, grid);
        cnt += dfs(row, col + 1, id, grid);
        cnt += dfs(row, col - 1, id, grid);

        return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        unordered_map<int, int> mp;
        int id = 2;
        int ans = 0;

        // Step 1: Identify all existing islands
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, id, grid);
                    mp[id] = size;
                    ans = max(ans, size);
                    id++;
                }
            }
        }

        // Step 2: Try converting every 0 into 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0) {

                    unordered_set<int> st;

                    int cnt = 1;

                    int dr[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < m &&
                            grid[nr][nc] > 1) {

                            st.insert(grid[nr][nc]);
                        }
                    }

                    // Add sizes of unique neighboring islands
                    for (auto island : st) {
                        cnt += mp[island];
                    }

                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};
