class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int n=nums.size();
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum%k==0) cnt+=1;
            int rem=sum%k;
            if(rem<0) rem+=k;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[rem];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};