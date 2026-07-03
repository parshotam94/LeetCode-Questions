class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int avg=sum/k;
        if(avg>=threshold) cnt++;
        for(int i=k;i<n;i++){
            sum+=(arr[i]-arr[i-k]);
            avg=sum/k;
            if(avg>=threshold) cnt++;
        }
        return cnt;
    }
};