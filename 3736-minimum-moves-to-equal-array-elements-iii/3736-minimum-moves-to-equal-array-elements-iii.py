class Solution:
    def minMoves(self, nums: List[int]) -> int:
        maxi=max(nums)
        res=0
        for val in nums:
            res+=(maxi-val)
        return res