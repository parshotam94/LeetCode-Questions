
class Solution:
    def totalStrength(self, strength: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(strength)

        # Previous strictly smaller element
        left = [-1] * n
        st = []

        for i in range(n):
            while st and strength[st[-1]] >= strength[i]:
                st.pop()

            left[i] = st[-1] if st else -1
            st.append(i)

        # Next smaller or equal element
        right = [n] * n
        st = []

        for i in range(n-1, -1, -1):
            while st and strength[st[-1]] > strength[i]:
                st.pop()

            right[i] = st[-1] if st else n
            st.append(i)

        # First prefix sum
        prefix = [0] * (n+1)

        for i in range(n):
            prefix[i+1] = (prefix[i] + strength[i]) % MOD

        # Second prefix sum
        pp = [0] * (n+2)

        for i in range(n+1):
            pp[i+1] = (pp[i] + prefix[i]) % MOD

        ans = 0

        for i in range(n):
            l = left[i]
            r = right[i]

            L = i-l
            R = r-i

            sumRight = (pp[r+1] - pp[i+1]) % MOD
            sumLeft = (pp[i+1] - pp[l+1]) % MOD

            contribution = (
                L * sumRight - R * sumLeft
            ) % MOD

            ans = (
                ans + strength[i] * contribution
            ) % MOD

        return ans
