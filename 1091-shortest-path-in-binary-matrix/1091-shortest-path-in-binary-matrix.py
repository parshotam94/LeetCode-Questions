class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n, m=len(grid), len(grid[0])
        if grid[0][0]==1 or grid[n-1][m-1]==1:
            return -1
        if n==1:
            return 1
        INF=10**18
        dist=[[INF]*m for _ in range(n)]
        vis=[[False]*m for _ in range(n)]
        q=deque()
        dist[0][0]=1
        vis[0][0]=True
        q.append((0, 0, 1))
        while q:
            row, col, dis=q.popleft()
            for i in range(-1, 2):
                for j in range(-1, 2):
                    if i==0 and j==0:
                        continue
                    nrow=row+i
                    ncol=col+j
                    if nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==0 and not vis[nrow][ncol] and dis+1<dist[nrow][ncol]:
                        dist[nrow][ncol]=dis+1
                        vis[nrow][ncol]=True
                        if nrow==n-1 and ncol==m-1:
                            return dis+1
                        q.append((nrow, ncol, dis+1))
        return -1
