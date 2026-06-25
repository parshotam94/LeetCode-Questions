class Solution {
public:
    bool rotateString(string s, string goal) {
        // unordered_map<char, int>mpp;
        // for(char ch: s){
        //     mpp[ch]++;
        // }
        // for(char ch: goal){
        //     mpp[ch]--;
        // }
        // for(auto it: mpp){
        //     if(it.second>0) return false;
        // }
        // return true;
        if(s.size()!=goal.size()) return false;
        return (s+s).find(goal)!=string::npos;
    }
};