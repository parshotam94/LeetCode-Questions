class Solution {
public:
    bool helper(vector<int>& nums, int idx, int target,
                vector<vector<int>>& dp) {

        if(target == 0)
            return true;

        if(idx == 0)
            return nums[0] == target;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = helper(nums, idx-1, target, dp);

        bool take = false;
        if(nums[idx] <= target)
            take = helper(nums, idx-1, target-nums[idx], dp);

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum & 1)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(target+1, -1));

        return helper(nums, nums.size()-1, target, dp);
    }
};