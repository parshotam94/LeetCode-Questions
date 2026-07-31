class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        n, m=len(mat), len(mat[0])
        vis=[[False]*m for _ in range(n)]
        dist=[[0]*m for _ in range(n)]
        q=deque()
        for i in range(n):
            for j in range(m):
                if mat[i][j]==0:
                    vis[i][j]=True
                    q.append((i, j, 0))
        directions=[(-1, 0), (0, 1), (1, 0), (0, -1)]
        while q:
            row, col, steps=q.popleft()
            dist[row][col]=steps
            for dx, dy in directions:
                nrow=dx+row
                ncol=dy+col
                if nrow>=0 and nrow<n and ncol>=0 and ncol<m and not vis[nrow][ncol]:
                    vis[nrow][ncol]=True
                    q.append((nrow, ncol, steps+1))
        return dist
        