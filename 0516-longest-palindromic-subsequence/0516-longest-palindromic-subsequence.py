class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        t=s[::-1]
        n=len(s)
        dp=[[-1]*(n) for _ in range(n)]
        def helper(s, t, idx1, idx2, dp):
            if idx1<0 or idx2<0:
                return 0
            if dp[idx1][idx2]!=-1:
                return dp[idx1][idx2]
            if s[idx1]==t[idx2]:
                dp[idx1][idx2]=1+helper(s, t, idx1-1, idx2-1, dp)
            else:
                dp[idx1][idx2]=max(helper(s, t, idx1-1, idx2, dp), helper(s, t, idx1, idx2-1, dp))
            return dp[idx1][idx2]
        return helper(s, t, n-1, n-1, dp)
             

        