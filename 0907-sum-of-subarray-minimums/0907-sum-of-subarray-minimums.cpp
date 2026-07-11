class Solution {
public:
    int mod=1e9+7;
    vector<int>nse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nextSmaller(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nextSmaller[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nextSmaller;
    }
    vector<int>pse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>prevSmaller(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            prevSmaller[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return prevSmaller;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nextSmaller=nse(arr);
        vector<int>prevSmaller=pse(arr);
        int total=0;
        for(int i=0;i<n;i++){
            int left=i-prevSmaller[i];
            int right=nextSmaller[i]-i;
            total=(total+(right*left*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};