class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        res=[]
        def find(nums, ans, i):
            if i==len(nums):
                ans.append(list(nums))
                return
            for idx in range(i, len(nums)):
                nums[idx], nums[i]=nums[i], nums[idx]
                find(nums, ans, i+1)
                nums[idx], nums[i]=nums[i], nums[idx]
        find(nums, ans, 0)
        return ans