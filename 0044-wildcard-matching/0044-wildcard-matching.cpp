class Solution {
public:
    bool helper(string &s, string &p, int i, int j,
                vector<vector<int>>& dp) {

        // Both exhausted
        if(i < 0 && j < 0)
            return true;

        // Pattern exhausted but string remains
        if(j < 0)
            return false;

        // String exhausted
        // Remaining pattern must contain only '*'
        if(i < 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        // Character match or '?'
        if(p[j] == s[i] || p[j] == '?') {
            return dp[i][j] =
                helper(s, p, i-1, j-1, dp);
        }

        // '*' -> two choices
        if(p[j] == '*') {

            // '*' matches zero characters
            bool zero = helper(s, p, i, j-1, dp);

            // '*' matches one/more characters
            bool oneOrMore = helper(s, p, i-1, j, dp);

            return dp[i][j] = zero || oneOrMore;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return helper(s, p, n-1, m-1, dp);
    }
};