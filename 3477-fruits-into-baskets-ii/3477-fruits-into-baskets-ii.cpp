class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt=0;
        vector<bool>vis(baskets.size(), false);
        for(int fruit: fruits){
            bool placed=false;
            for(int i=0;i<baskets.size();i++){
                if(fruit<=baskets[i] && !vis[i]){
                    placed=true;
                    vis[i]=true;
                    break;
                }
            }
            if(!placed){
                cnt+=1;
            }
        }
        return cnt;
    }
};