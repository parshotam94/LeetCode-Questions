class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        for(int val: nums){
            mpp[val]++;
        }
        vector<pair<int, int>> pairs;
        for(auto it: mpp){
            pairs.push_back({it.first, it.second});
        }
        sort(pairs.begin(), pairs.end(), [](auto& a, auto &b){
            return a.second>b.second;
        });
        int idx=0;
        vector<int>ans;
        while(k--){
            ans.push_back(pairs[idx++].first);
        }
        return ans;
    }
};