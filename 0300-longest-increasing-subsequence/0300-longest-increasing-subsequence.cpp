class Solution {
public:
    int helper(vector<int>&nums, int idx, int prev, vector<vector<int>>&dp){
        if(idx==nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int len=helper(nums, idx+1, prev, dp);
        if(prev==-1 || nums[idx]>nums[prev]){
            len=max(len, 1+helper(nums, idx+1, idx, dp));
        }
        return dp[idx][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return helper(nums, 0, -1, dp);
    }
};