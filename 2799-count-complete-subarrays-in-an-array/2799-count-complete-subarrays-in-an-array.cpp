class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int totalDist=unordered_set<int>(nums.begin(), nums.end()).size();
        int left=0, cnt=0;
        for(int right=0;right<nums.size();++right){
            mpp[nums[right]]++;
            while(mpp.size()==totalDist){
                cnt+=nums.size()-right;
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) mpp.erase(nums[left]);
                left++;
            }
            
        }
        return cnt;
    }
};