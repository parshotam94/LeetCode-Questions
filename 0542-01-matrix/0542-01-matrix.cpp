class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>dist(n, vector<int>(m, 0));
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            dist[row][col]=steps;
            q.pop();
            int delrow[4]={-1, 0, 1, 0};
            int delcol[4]={0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return dist;
    }
};