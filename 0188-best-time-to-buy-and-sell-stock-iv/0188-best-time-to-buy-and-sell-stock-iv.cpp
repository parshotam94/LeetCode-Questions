class Solution {
public:
    int profit=0;
    int helper(int idx, vector<int>&prices, vector<vector<vector<int>>>&dp, bool buy, int cap){
        if(cap==0) return 0;
        if(idx==prices.size()) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        if(buy){
            profit=max(-prices[idx]+helper(idx+1, prices, dp, 0, cap), helper(idx+1, prices, dp, 1, cap));
        }
        else{
            profit=max(prices[idx]+helper(idx+1, prices, dp, 1, cap-1), helper(idx+1, prices, dp, 0, cap));
        }
        return dp[idx][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return helper(0, prices, dp, 1, k);
    }
};