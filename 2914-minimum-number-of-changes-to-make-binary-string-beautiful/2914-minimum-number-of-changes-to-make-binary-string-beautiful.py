class Solution:
    def minChanges(self, s: str) -> int:
        cnt=0
        for i in range(0, len(s), 2):
            first=s[i]
            second=s[i+1]
            if first!=second:
                cnt+=1
        return cnt
        