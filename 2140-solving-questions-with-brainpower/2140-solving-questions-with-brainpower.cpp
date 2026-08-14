class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();

        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int next = i + q[i][1] + 1;

            long long take = q[i][0];

            if (next < n)
                take += dp[next];

            long long skip = dp[i + 1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};