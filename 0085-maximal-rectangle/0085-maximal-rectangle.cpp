class Solution {
public:
    int area(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        int maxArea=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[i]<heights[st.top()])){
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                maxArea=max(maxArea, height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        vector<int>hist(m, 0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    hist[j]++;
                }
                else{
                    hist[j]=0;
                }
            }
            ans=max(ans, area(hist));
        }
        return ans;
    }
};