class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int val: stones) pq.push(val);
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x!=y){
                y-=x;
                pq.push(y);
            }
        }
        return pq.empty()?0:pq.top();
    }
};