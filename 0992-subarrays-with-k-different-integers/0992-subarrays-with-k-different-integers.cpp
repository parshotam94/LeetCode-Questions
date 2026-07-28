class Solution {
public:
    int atmost(vector<int>& nums, int k){
        unordered_map<int, int>mpp;
        int left=0;
        int cnt=0;
        int dist=0;
        for(int right=0;right<nums.size();right++){
            mpp[nums[right]]++;
            if(mpp[nums[right]]==1) dist++;
            while(dist>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) dist--;
                left++;
            }
            cnt+=(right-left+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k)-atmost(nums, k-1);
    }
};