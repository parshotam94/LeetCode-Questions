class Solution(object):
    def findSubsequences(self, nums):

        ans = []
        path = []

        def dfs(index):

            if len(path) >= 2:
                ans.append(path[:])

            used = set()

            for i in range(index, len(nums)):

                if nums[i] in used:
                    continue

                if len(path) == 0 or nums[i] >= path[-1]:

                    used.add(nums[i])
                    path.append(nums[i])

                    dfs(i + 1)

                    path.pop()

        dfs(0)

        return ans