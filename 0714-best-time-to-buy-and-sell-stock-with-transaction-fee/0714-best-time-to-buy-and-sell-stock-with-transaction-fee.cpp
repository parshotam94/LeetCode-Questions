class Solution {
public:
    int profit=0;
    int helper(int idx, vector<int>&prices, vector<vector<int>>&dp, bool buy, int fee){
        if(idx>=prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            profit=max(-prices[idx]+helper(idx+1, prices, dp, 0, fee), helper(idx+1, prices, dp, 1, fee));
        }
        else{
            profit=max((prices[idx]-fee)+helper(idx+1, prices, dp, 1, fee), helper(idx+1, prices, dp, 0, fee));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(0, prices, dp, 1, fee);
    }
};