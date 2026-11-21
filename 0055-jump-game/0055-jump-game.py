class Solution:
    def canJump(self, nums: list[int]) -> bool:
        maxJump=0
        for i, val in enumerate(nums):
            if(maxJump<i):
                return False
            maxJump=max(maxJump, i+val)
        return True