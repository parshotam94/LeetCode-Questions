class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i, j}, 0}); //row, col, time;
                    vis[i][j]=true;
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int t=q.front().second;
            int row=q.front().first.first;
            int col=q.front().first.second;
            q.pop();
            time=max(time, t);
            int delrow[4]={-1, 0, 1, 0}; // top, right, bottom, left;
            int delcol[4]={0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return time;
    }
};