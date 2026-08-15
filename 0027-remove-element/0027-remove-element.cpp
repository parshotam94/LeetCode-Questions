class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx=0;
        for(int it: nums){
            if(it!=val){
                nums[idx++]=it;
            }
        }
        return idx;
    }
};