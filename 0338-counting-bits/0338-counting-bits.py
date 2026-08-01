class Solution:
    def helper(self, i):
        cnt=0
        while i:
            cnt+=1
            i=i&(i-1)
        return cnt
    def countBits(self, n: int) -> List[int]:
        ans=[]
        for i in range(n+1):
            ans.append(self.helper(i))
        return ans