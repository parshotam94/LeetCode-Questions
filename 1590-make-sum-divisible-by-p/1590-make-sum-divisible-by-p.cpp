class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long rem = totalSum % p;

        if (rem == 0) return 0;

        unordered_map<long long, int> mpp;

        long long sum = 0;
        int len = n;

        mpp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            long long currMod = sum % p;
            long long targetMod = (currMod - rem + p) % p;

            if (mpp.find(targetMod) != mpp.end()) {
                len = min(len, i - mpp[targetMod]);
            }

            mpp[currMod] = i;
        }

        return len == n ? -1 : len;
    }
};