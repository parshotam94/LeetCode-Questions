class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j,
               vector<vector<int>>& dp,
               vector<vector<bool>>& vis) {

        int n = triangle.size();

        if(i == n - 1)
            return triangle[i][j];

        if(vis[i][j])
            return dp[i][j];

        vis[i][j] = true;

        int down = helper(triangle, i + 1, j, dp, vis);
        int diagonal = helper(triangle, i + 1, j + 1, dp, vis);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        return helper(triangle, 0, 0, dp, vis);
    }
};