class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end());
        int cnt=1;
        int last=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>last){
                cnt+=1;
                last=points[i][1];
            }
            else{
                last=min(last, points[i][1]);
            }
        }
        return cnt;
    }
};