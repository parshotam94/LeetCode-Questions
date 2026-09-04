class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>preMax(n, 0);
        vector<int>preMin(n, 0);
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            preMax[i]=maxi;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mini){
                mini=nums[i];
            }
            preMin[i]=mini;
        }
        for(int i=0;i<n;i++){
            if(preMax[i]-preMin[i]<=k) return i;
        }
        return -1;
    }
};