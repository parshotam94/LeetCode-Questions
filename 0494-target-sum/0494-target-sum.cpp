class Solution {
public:
    int helper(vector<int>& nums, int target, int idx,
               vector<vector<int>>& dp) {

        if(idx == 0){
            if(target == 0 && nums[0] == 0)
                return 2;
            if(target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if(dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = helper(nums, target, idx-1, dp);

        int take = 0;
        if(nums[idx] <= target)
            take = helper(nums, target-nums[idx], idx-1, dp);

        return dp[idx][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum - target < 0 || (sum - target) % 2)
            return 0;

        int req = (sum - target) / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(req+1, -1));

        return helper(nums, req, nums.size()-1, dp);
    }
};