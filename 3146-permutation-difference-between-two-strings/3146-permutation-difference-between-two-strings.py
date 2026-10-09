class Solution:
    def findPermutationDifference(self, s, t):
        # Intuition: check every pair to find the matching char, sum index differences
        n = len(s)
        result = 0
        for i in range(n):
            for j in range(n):
                if s[i] == t[j]:
                    result += abs(i - j)
                    break
        return result