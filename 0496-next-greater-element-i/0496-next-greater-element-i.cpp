class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()) res.push_back(-1);
            else res.push_back(st.top());
            st.push(nums2[i]);
        }
        reverse(res.begin(), res.end());
        map<int, int>mpp;
        int i=0;
        for(int val: nums2){
            mpp[val]=res[i++];
        }
        vector<int>ans;
        for(int val: nums1){
            ans.push_back(mpp[val]);
        }
        return ans;
    }
};