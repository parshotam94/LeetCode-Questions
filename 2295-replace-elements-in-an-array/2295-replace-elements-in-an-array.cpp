class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        unordered_map<int, int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }
        for(auto it: operations){
            int u=it[0], v=it[1];
            if(mpp.find(u)!=mpp.end()){
                int idx=mpp[u];
                nums[idx]=v;
                mpp[v]=idx;
            }
        }
        return nums;
    }
};