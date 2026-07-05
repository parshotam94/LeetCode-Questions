class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans=[]
        res=[]
        def helper(candidates, ans, res, target, idx):
            if idx==len(candidates):
                if target==0:
                    ans.append(list(res))
                return
            if candidates[idx]<=target:
                res.append(candidates[idx])
                helper(candidates, ans, res, target-candidates[idx], idx)
                res.pop()
            helper(candidates, ans, res, target, idx+1)
        helper(candidates, ans, res, target, 0)
        return ans
            
        