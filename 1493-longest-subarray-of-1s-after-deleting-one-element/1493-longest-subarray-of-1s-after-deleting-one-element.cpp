class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0, ans=0, cnt=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0) cnt++;
            while(cnt>1){
                if(nums[left]==0) cnt--;
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans-1;
    }
};