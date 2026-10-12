class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        unordered_map<int, int>mpp;
        vector<int>repeated;
        for(int val: nums1) mpp[val]++;
        for(int val: nums2){
            if(mpp.find(val)!=mpp.end()) repeated.push_back(val);
        }
        if(repeated.size()>0) return *min_element(repeated.begin(), repeated.end());
        int first_min=*min_element(nums1.begin(), nums1.end());
        int second_min=*min_element(nums2.begin(), nums2.end());
        if(first_min<second_min){
            return first_min*10+second_min;
        }
        return second_min*10+first_min;
    }
};