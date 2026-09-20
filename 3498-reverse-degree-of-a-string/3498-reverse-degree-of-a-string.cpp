class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            ans+=((26-(ch-'a'))*(i+1));
        }
        return ans;
    }
};