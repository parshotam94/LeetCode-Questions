class Solution:
    def helper(self, text1, text2, dp, idx1, idx2):
        if idx1 < 0 or idx2 < 0:
            return 0

        if dp[idx1][idx2] != -1:
            return dp[idx1][idx2]

        if text1[idx1] == text2[idx2]:
            dp[idx1][idx2] = 1 + self.helper(
                text1, text2, dp, idx1 - 1, idx2 - 1
            )
        else:
            dp[idx1][idx2] = max(
                self.helper(text1, text2, dp, idx1 - 1, idx2),
                self.helper(text1, text2, dp, idx1, idx2 - 1)
            )

        return dp[idx1][idx2]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[-1] * len(text2) for _ in range(len(text1))]
        return self.helper(text1, text2, dp, len(text1) - 1, len(text2) - 1)