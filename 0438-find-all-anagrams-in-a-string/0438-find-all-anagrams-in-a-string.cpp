class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.size();
        unordered_map<char, int>mp1, mp2;
        for(char ch: p){
            mp1[ch]++;
        }
        for(int i=0;i<k;i++){
            mp2[s[i]]++;
        }
        vector<int>ans;
        if(mp1==mp2) ans.push_back(0);
        for(int i=k;i<s.size();i++){
            mp2[s[i-k]]--;
            if(mp2[s[i-k]]==0) mp2.erase(s[i-k]);
            mp2[s[i]]++;
            if(mp1==mp2) ans.push_back(i-k+1);
        }
        return ans;
    }
};