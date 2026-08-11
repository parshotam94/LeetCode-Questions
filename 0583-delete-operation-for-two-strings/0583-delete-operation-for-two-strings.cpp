class Solution {
public:
    int helper(string word1, string word2, vector<vector<int>>&dp, int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=1+helper(word1, word2, dp, i-1, j-1);
        return dp[i][j]=max(helper(word1, word2, dp, i-1, j), helper(word1, word2, dp, i, j-1));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        helper(word1, word2, dp, n-1, m-1);
        int len=dp[n-1][m-1];
        return n+m-(2*len);
    }
};