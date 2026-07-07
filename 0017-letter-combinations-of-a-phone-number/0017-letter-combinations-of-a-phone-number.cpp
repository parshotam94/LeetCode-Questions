class Solution {
public:
    void helper(int idx, string combinations[], string s, vector<string>&ans, string digits){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit=digits[idx]-'0';
        for(int i=0;i<combinations[digit].size();i++){
            helper(idx+1, combinations, s+combinations[digit][i], ans, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combinations[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s="";
        vector<string>ans;
        helper(0, combinations, s, ans, digits);
        return ans;
    }
};