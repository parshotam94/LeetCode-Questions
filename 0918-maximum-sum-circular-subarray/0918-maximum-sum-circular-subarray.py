class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        totalSum = sum(nums)

        currMax = currMin = 0
        maxSum = float('-inf')
        minSum = float('inf')

        for num in nums:
            currMax = max(num, currMax + num)
            maxSum = max(maxSum, currMax)

            currMin = min(num, currMin + num)
            minSum = min(minSum, currMin)

        # If all elements are negative, return the largest element.
        if maxSum < 0:
            return maxSum

        return max(maxSum, totalSum - minSum)