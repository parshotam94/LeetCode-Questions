class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int sum=0;
        int len=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i]==0?-1: 1;
            if(sum==0) len=i+1;
            else if(mpp.find(sum)!=mpp.end()){
                len=max(len, i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return len;
    }
};