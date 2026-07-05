class Solution(object):
    def combinationSum3(self, k, n):

        ans = []
        res = []

        def helper(n, idx):

            if n == 0 and len(res) == k:
                ans.append(res[:])
                return

            if n < 0 or len(res) > k:
                return

            for i in range(idx, 10):

                if i > n:
                    break

                res.append(i)
                helper(n - i, i + 1)
                res.pop()

        helper(n, 1)

        return ans