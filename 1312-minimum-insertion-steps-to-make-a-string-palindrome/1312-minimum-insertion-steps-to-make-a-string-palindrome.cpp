class Solution {
public:
    vector<vector<int>> dp;

    int func(string &s, int i, int j) {
        if(i > j) return 0;
        if(i == j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = 2 + func(s, i + 1, j - 1);
        }

        int opt1 = func(s, i + 1, j);
        int opt2 = func(s, i, j - 1);

        return dp[i][j] = max(opt1, opt2);
    }

    int minInsertions(string s) {
        int n = s.size();

        dp.assign(n, vector<int>(n, -1));

        return n - func(s, 0, n - 1);
    }
};