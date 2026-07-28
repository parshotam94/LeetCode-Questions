class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax=nums[0];
        int currMin=nums[0];
        int maxNum=nums[0];
        for(int i=1;i<nums.size();i++){
            int tempMax=currMax;
            currMax=max(nums[i], max(currMax*nums[i], currMin*nums[i]));
            currMin=min(nums[i], min(tempMax*nums[i], currMin*nums[i]));
            maxNum=max(maxNum, currMax);
        }
        return maxNum;

    }
};