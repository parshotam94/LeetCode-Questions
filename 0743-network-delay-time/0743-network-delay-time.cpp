class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>adj[n+1];
        for(auto &it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int>dist(n+1, 1e9);
        dist[k]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it: adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;
                if(dis+edgeWt<dist[adjNode]){
                    dist[adjNode]=dis+edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans=*max_element(dist.begin()+1, dist.end());
        return ans==1e9?-1:ans;
    }
};