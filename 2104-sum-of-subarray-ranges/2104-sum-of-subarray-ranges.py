class Solution:
    def sub_mins(self, arr: list[int])->int:
        n=len(arr)
        st=[]
        res=[0]*n
        for i in range(n):
            while st and arr[st[-1]]>arr[i]:
                st.pop()
            j=st[-1] if st else -1
            res[i]=res[j]+(i-j)*arr[i]
            st.append(i)
        return res
    def sub_maxs(self, arr: list[int])->int:
        n=len(arr)
        st=[]
        res=[0]*n
        for i in range(n-1, -1, -1):
            while st and arr[st[-1]]<arr[i]:
                st.pop()
            j=st[-1] if st else n
            res[i]=(res[j] if j!=n else 0) +(j-i)*arr[i]
            st.append(i)
        return res
    def subArrayRanges(self, nums: list[int]) -> int:
        return sum(self.sub_maxs(nums))-sum(self.sub_mins(nums))