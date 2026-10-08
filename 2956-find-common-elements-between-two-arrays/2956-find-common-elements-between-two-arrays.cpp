class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int cnt=0;
        for(int val: nums1){
            for(int v: nums2){
                if(val==v){
                    cnt++;
                    break;
                }
            }
        }
        ans.push_back(cnt);
        cnt=0;
        for(int val: nums2){
            for(int v: nums1){
                if(val==v){
                    cnt++;
                    break;
                }
            }
        }
        ans.push_back(cnt);
        return ans;
    }
};