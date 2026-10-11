class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }
        for(int val: nums){
            if(val==0) cnt++;
        }
        vector<int>ans;
        for(int val: nums){
            if(val!=0) ans.push_back(val);
        }
        while(cnt--){
            ans.push_back(0);
        }
        return ans;
    }
};