class Solution:
    def largestHist(self, arr: list[int])->int:
        n=len(arr)
        st=[]
        maxi=0
        for i in range(n+1):
            while st and (i==n or arr[st[-1]]>arr[i]):
                height=arr[st[-1]]
                st.pop()
                width=i-st[-1]-1 if st else i
                maxi=max(maxi, height*width)
            if i<n:
                st.append(i)
        return maxi 
    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        n=len(matrix)
        m=len(matrix[0])
        maxSum=0
        preSum=[[0 for j in range(m)] for i in range(n)]
        for j in range(m):
            sumi=0
            for i in range(n):
                sumi+=int(matrix[i][j])
                if matrix[i][j]=='0':
                    sumi=0
                preSum[i][j]=sumi
        for i in range(n):
            maxSum=max(maxSum, self.largestHist(preSum[i]))
        return maxSum


