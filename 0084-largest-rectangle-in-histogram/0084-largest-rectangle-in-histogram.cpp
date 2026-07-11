class Solution {
public:
    // vector<int> nextSmaller(vector<int>& heights){
    //     int n=heights.size();
    //     vector<int>ans(n);
    //     stack<int>st;
    //     for(int i=n-1;i>=0;i--){
    //         while(!st.empty() && heights[st.top()]>=heights[i]){
    //             st.pop();
    //         }
    //         ans[i]=st.empty()?n-1:st.top()-1;
    //         st.push(i);
    //     }
    //     return ans;
    // }
    // vector<int> prevSmaller(vector<int>& heights){
    //     int n=heights.size();
    //     vector<int>ans(n);
    //     stack<int>st;
    //     for(int i=0;i<n;i++){
    //         while(!st.empty() && heights[st.top()]>=heights[i]){
    //             st.pop();
    //         }
    //         ans[i]=st.empty()?0:st.top()+1;
    //         st.push(i);
    //     }
    //     return ans;
    // }
    // int largestRectangleArea(vector<int>& heights) {
    //     int n=heights.size();
    //     vector<int>nse=nextSmaller(heights);
    //     vector<int>pse=prevSmaller(heights);
    //     int maxi=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         maxi=max(maxi, (heights[i]*(nse[i]-pse[i]+1)));
    //     }
    //     return maxi;
    // }
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && ((i==n)|| heights[st.top()]>=heights[i])){
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                maxi=max(maxi, height*width);
            }
            st.push(i);
        }
        return maxi;
    }
};