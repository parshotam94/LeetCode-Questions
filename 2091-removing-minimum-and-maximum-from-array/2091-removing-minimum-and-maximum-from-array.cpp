class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int delFromFront=0, delFromBack=0, delFromBoth=0;
        int maxi=*max_element(nums.begin(), nums.end());
        int mini=*min_element(nums.begin(), nums.end());
        int idxOfMin=-1, idxOfMax=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                idxOfMax=i;
            }
            if(nums[i]==mini){
                idxOfMin=i;
            }
        }
        int largestIdx=max(idxOfMax, idxOfMin);
        int smallestIdx=min(idxOfMax, idxOfMin);
        delFromFront=largestIdx+1;
        delFromBack=n-smallestIdx;
        int tillSmallest=smallestIdx+1;
        int tillLargest=n-largestIdx;
        delFromBoth=tillSmallest+tillLargest;
        return min({delFromBoth, delFromFront, delFromBack});
    }

};