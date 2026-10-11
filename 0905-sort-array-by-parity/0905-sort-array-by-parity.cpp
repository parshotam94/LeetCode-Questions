class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>even, odd;
        for(int val: nums){
            if(val%2) odd.push_back(val);
            else even.push_back(val);
        }
        for(int val: odd){
            even.push_back(val);
        }
        return even;
    }
};