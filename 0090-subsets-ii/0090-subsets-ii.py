class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        res=[]
        nums.sort()
        def find_all(nums, ans, res, i):
            if i==len(nums):
                ans.append(list(res))
                return
            res.append(nums[i])
            find_all(nums, ans, res, i+1)
            res.pop()
            idx=i+1
            while(idx<len(nums) and nums[idx]==nums[idx-1]):
                idx+=1
            find_all(nums, ans, res, idx)
        find_all(nums, ans, res, 0)
        return ans
        