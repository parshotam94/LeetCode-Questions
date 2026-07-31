class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>dist(n, vector<int>(m,  INT_MAX));
        dist[0][0]=0;
        pq.push({0, {0, 0}});
        int delrow[4]={0, 1, 0, -1};
        int delcol[4]={-1, 0, 1, 0};
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 and col==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int newEff = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                    if(newEff<dist[nrow][ncol]){
                        dist[nrow][ncol]=newEff;
                        pq.push({newEff, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};