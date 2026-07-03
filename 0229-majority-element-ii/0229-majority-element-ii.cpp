class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int>mpp;
        for(int val: nums){
            mpp[val]++;
        }
        vector<int>ans;
        int maxi=floor(n/3);
        for(auto it: mpp){
            if(it.second>maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};