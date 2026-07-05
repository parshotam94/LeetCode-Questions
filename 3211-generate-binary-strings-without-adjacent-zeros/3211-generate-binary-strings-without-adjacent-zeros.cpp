class Solution {
public:
    void helper(int n, string curr, vector<string>&res){
        if(curr.length()==n){
            res.push_back(curr);
            return;
        }
        helper(n, curr+'1', res);
        if(curr.empty() || curr.back()!='0'){
            helper(n, curr+'0', res);
        }
    }
    vector<string> validStrings(int n) {
        vector<string>res;
        helper(n, "", res);
        return res;
    }
};