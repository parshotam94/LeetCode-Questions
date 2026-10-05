class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(int val: gifts) pq.push(val);
        while(k--){
            int x=pq.top();
            pq.pop();
            x=sqrt(x);
            pq.push(x);
        }
        while(!pq.empty())
       {
            int x = pq.top();
            pq.pop();
            ans+=x;
       }
       return ans; 
    }
};