class Solution(object):

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans=[]
        res=[]
        def find_sub(nums, ans, res, i):
            if i==len(nums):
                ans.append(list(res))
                return
            res.append(nums[i])
            find_sub(nums, ans, res, i+1)
            res.pop()
            find_sub(nums, ans, res, i+1)

        find_sub(nums, ans, res, 0)
        return ans
        