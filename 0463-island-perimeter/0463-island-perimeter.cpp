class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int island=0, neigh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    island++;
                    if(i<n-1 && grid[i+1][j]==1) neigh++;
                    if(j<m-1 && grid[i][j+1]==1) neigh++;
                }
            }
        }
        return island*4-neigh*2;
    }
};