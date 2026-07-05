class Solution {
public:
    void helper(int n, vector<string>&ans){
        if(n==0){
            return;
        }
        helper(n-1, ans);
        if(n%3==0 && n%5==0){
            ans.push_back("FizzBuzz");
        }
        else if(n%3==0){
            ans.push_back("Fizz");
        }
        else if(n%5==0){
            ans.push_back("Buzz");
        }
        else{
            ans.push_back(to_string(n));
        }
    }
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        helper(n, ans);
        return ans;
    }
};