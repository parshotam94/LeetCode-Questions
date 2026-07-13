class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int open=0;
        int ans=0;
        for(char ch: s){
            if(ch=='('){
                open++;
            }
            else if(ch==')'){
                open--;
            }
            ans=max(ans, open);
        }
        return ans;
    }
};