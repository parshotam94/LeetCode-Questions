class Solution {
public:
    int mod=1e9+7;
    vector<int> nextSmaller(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextGreater(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevGreater(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    long long subArrayMax(vector<int>& arr){
        int n=arr.size();
        vector<int>nge=nextGreater(arr);
        vector<int>pge=prevGreater(arr);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-pge[i];
            int right=nge[i]-i;
            sum=(sum+(left*right*1LL*arr[i]));
        }
        return sum;
    }
    long long subArrayMin(vector<int>& arr){
        int n=arr.size();
        vector<int>nse=nextSmaller(arr);
        vector<int>pse=prevSmaller(arr);
        long long sum=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            sum=(sum+(left*right*1LL*arr[i]));
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& arr) {
        return subArrayMax(arr)-subArrayMin(arr);
    }
};