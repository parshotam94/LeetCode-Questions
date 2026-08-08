class DSU{
vector<int>parent, rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node]=find(parent[node]);
    }
    void Union(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU d(n);
        unordered_map<string, int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    d.Union(i, mpp[mail]);
                }
            }
        }
        vector<string>merge[n];
        for(auto it: mpp){
            string mail=it.first;
            int node=d.find(it.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merge[i].size()==0) continue;
            sort(merge[i].begin(), merge[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};