class Solution:
    def maxWidthRamp(self, nums: list[int]) -> int:
        st=[]
        res=0
        for i in range(len(nums))[::-1]:
            if not st or nums[i]>st[-1][0]:
                st.append([nums[i], i])
            else:
                j=st[bisect.bisect(st, [nums[i], i])][1]
                res=max(res, j-i)
        return res