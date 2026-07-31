class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, k):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type k: int
        :rtype: int
        """
        adj=[[] for _ in range(n)]
        for u, v, wt in flights:
            adj[u].append((v, wt))
        q=deque()
        q.append((0, src, 0))
        INF=10**18
        dist=[INF]*n
        dist[src]=0
        while q:
            stops, node, cost=q.popleft()
            if stops>k:
                continue
            for adjNode, edWt in adj[node]:
                if cost+edWt<dist[adjNode] and stops<=k:
                    dist[adjNode]=cost+edWt
                    q.append((stops+1, adjNode, cost+edWt))
        if dist[dst]==INF:
            return -1
        return dist[dst]