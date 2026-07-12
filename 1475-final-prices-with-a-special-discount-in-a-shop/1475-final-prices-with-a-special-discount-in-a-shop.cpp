class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && prices[st.top()]>prices[i]){
                st.pop();
            }
            nse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nse[i]!=-1 && prices[nse[i]]<=prices[i] && nse[i]>i){
                ans.push_back(prices[i]-prices[nse[i]]);
            }
            else{
                ans.push_back(prices[i]);
            }
        }
        return ans;
    }
};