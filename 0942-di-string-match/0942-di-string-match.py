class Solution:
    def diStringMatch(self, s: str) -> list[int]:
        ans=[]
        i=0
        j=len(s)
        for ch in s:
            if ch=='I':
                ans.append(i)
                i+=1
            else:
                ans.append(j)
                j-=1
        ans.append(j)
        return ans