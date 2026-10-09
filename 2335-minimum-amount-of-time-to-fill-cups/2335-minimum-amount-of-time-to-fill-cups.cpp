class Solution {
public:
    int fillCups(vector<int>& amount) 
    {
        int ans = 0;
        priority_queue<int>pq;
        for(int i=0;i<amount.size();i++)
        {
            if(amount[i]!=0) pq.push(amount[i]);
        }
        while(!pq.empty())
        {
            ans++;
            int x = pq.top();
            pq.pop();
            if(!pq.empty())
            {
                int y = pq.top();
                pq.pop();
                if(y-1!=0) pq.push(y-1);
            }
            if(x-1!=0) pq.push(x-1);
        }
        return ans;
    }
};