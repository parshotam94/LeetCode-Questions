class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        int n=grid.size(), m=grid[0].size();
        if(i>=n || j>=m) return 0;
        if(grid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=helper(grid, i+1, j, dp);
        int left=helper(grid, i, j+1, dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return helper(obstacleGrid, 0, 0, dp);
    }
};