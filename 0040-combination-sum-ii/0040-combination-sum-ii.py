class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        ans=[]
        res=[]
        def helper(candidates, ans, res, target, idx):
            if idx==len(candidates):
                if target==0:
                    ans.append(list(res))
                return
            if candidates[idx]<=target:
                res.append(candidates[idx])
                helper(candidates, ans, res, target-candidates[idx], idx+1)
                res.pop()
            i=idx+1
            while i<len(candidates) and candidates[i]==candidates[i-1]:
                i+=1
            helper(candidates, ans, res, target, i)
        helper(candidates, ans, res, target, 0)
        return ans
        