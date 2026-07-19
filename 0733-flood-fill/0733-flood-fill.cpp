class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m=image[0].size();
        queue<pair<int, int>>q;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int initColor=image[sr][sc];
        vis[sr][sc]=true;
        q.push({sr, sc});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            image[row][col]=color;
            int delrow[4]={1, 0, -1, 0};
            int delcol[4]={0, -1, 0, 1};
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initColor && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=true;
                }
            }
        }
        return image;
    }
};