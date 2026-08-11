class Solution {
public:
    int profit=0;
    int helper(int idx, vector<int>&prices, vector<vector<int>>&dp, bool buy){
        if(idx>=prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            profit=max(-prices[idx]+helper(idx+1, prices, dp, 0), helper(idx+1, prices, dp, 1));
        }
        else{
            profit=max(prices[idx]+helper(idx+2, prices, dp, 1), helper(idx+1, prices, dp, 0));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(0, prices, dp, 1);
    }
};