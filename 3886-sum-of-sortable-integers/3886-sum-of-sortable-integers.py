class Solution(object):
    def sortableIntegers(self, nums):
        n=len(nums)
        s_nums=sorted(nums)
        val_map={v: random.getrandbits(64) for v in set(nums)}
        pref_h=[0]*(n+1)
        pref_sh=[0]*(n+1)
        for i in range(n):
            pref_h[i+1]=pref_h[i]+val_map[nums[i]]
            pref_sh[i+1]=pref_sh[i]+val_map[s_nums[i]]
        drops=[0]*n
        for i in range(n-1):
            drops[i+1]=drops[i]+(1 if nums[i]>nums[i+1] else 0)
        total_sum=0
        for k in range(1, n+1):
            if n%k==0:
                possible=True
                for i in range(0, n, k):
                    if pref_h[i+k]-pref_h[i]!=pref_sh[i+k]-pref_sh[i]:
                        possible=False
                        break
                    d_count=drops[i+k-1]-drops[i]
                    if d_count>1 or (d_count==1 and nums[i+k-1]>nums[i]):
                        possible=False
                        break
                if possible:
                    total_sum+=k
        return total_sum
            