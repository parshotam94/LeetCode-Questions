class Solution:
    def helper(self, i):
        cnt=0
        while i:
            i=i&(i-1)
            cnt+=1
        return cnt
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        res=[False]*len(nums)
        sum=0
        for i, val in enumerate(nums):
            if(self.helper(i)==k):
                res[i]=True
        for i, val in enumerate(res):
            if val==True:
                sum+=nums[i]
        return sum
        