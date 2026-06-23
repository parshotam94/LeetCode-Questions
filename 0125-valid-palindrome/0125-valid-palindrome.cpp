class Solution {
public:
    bool isPalindrome(string s) {
        stack<char>st;
        string res="", ans="";
        for(char c: s){
            char ch=tolower(c);
            if((ch>='a' && ch<='z')||(ch>='0' && ch<='9')){
                st.push(ch);
                ans+=ch;
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return ans==res;
    }
};