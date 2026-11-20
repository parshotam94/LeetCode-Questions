class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mpp;
        for(auto e: edges){
            int u=e[0], v=e[1];
            mpp[u]++;
            mpp[v]++;
        }
        int maxi=INT_MIN;
        int ans=INT_MIN;
        for(auto it: mpp){
            int node=it.first;
            int freq=it.second;
            if(freq>maxi){
                ans=node;
                maxi=freq;
            }
        }
        return ans;
    }
};