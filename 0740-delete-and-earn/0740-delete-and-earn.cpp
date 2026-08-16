class Solution {
public:
    int helper(int x, vector<int>& points, vector<int>& dp) {

        if (x == 0)
            return 0;

        if (x == 1)
            return points[1];

        if (dp[x] != -1)
            return dp[x];

        int notPick = helper(x - 1, points, dp);

        int pick = points[x] + helper(x - 2, points, dp);

        return dp[x] = max(pick, notPick);
    }

    int deleteAndEarn(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> points(maxi + 1, 0);

        for (int x : nums) {
            points[x] += x;
        }

        vector<int> dp(maxi + 1, -1);

        return helper(maxi, points, dp);
    }
};