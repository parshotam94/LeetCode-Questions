class Solution {
public:
    int helper(vector<int>& nums, int idx, vector<int>& dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int pick = nums[idx] + helper(nums, idx - 2, dp);
        int notPick = helper(nums, idx - 1, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> temp1, temp2;

        for(int i = 0; i < n; i++){
            if(i != 0)
                temp1.push_back(nums[i]);

            if(i != n - 1)
                temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        return max(
            helper(temp1, temp1.size() - 1, dp1),
            helper(temp2, temp2.size() - 1, dp2)
        );
    }
};