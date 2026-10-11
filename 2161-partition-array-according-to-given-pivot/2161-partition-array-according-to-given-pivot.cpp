class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>left, right, middle;
        for(int val: nums){
            if(val<pivot){
                left.push_back(val);
            }
            else if(val==pivot) middle.push_back(val);
            else{
                right.push_back(val);
            }
        }
        for(int val: middle){
            left.push_back(val);
        }
        for(int val: right){
            left.push_back(val);
        }
        return left;
    }
};