class Solution:
    def helper(self, curr, ans, openCnt, closeCnt, n):
        if len(curr)==2*n:
            ans.append(curr)
            return
        if openCnt<n:
            self.helper(curr+'(', ans, openCnt+1, closeCnt, n)
        if closeCnt<openCnt:
            self.helper(curr+')', ans, openCnt, closeCnt+1, n)
    def generateParenthesis(self, n: int) -> List[str]:
        ans=[]
        self.helper("", ans, 0, 0, n)
        return ans