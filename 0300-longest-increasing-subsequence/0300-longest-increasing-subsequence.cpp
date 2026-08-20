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
        // int n=nums.size();
        // vector<vector<long long>>dp(n+1, vector<long long>(n+1, 0));
        // for(int idx=n-1;idx>=0;idx--){
        //     for(int prev=n-1;prev>=-1;prev--){
        //         long long len=dp[idx+1][prev+1];
        //         if(prev==-1 || nums[idx]>nums[prev]){
        //             len=max(len, 1LL+dp[idx+1][idx+1]);
        //         }
        //         dp[idx][prev+1]=len;
        //     }
        // }
        // return dp[0][0];
        //Binary Search
        vector<int>temp;
        temp.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return temp.size();
    }
};