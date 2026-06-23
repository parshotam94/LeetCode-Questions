class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        string ans="";
        while(i>=0){
            if(((int)num[i])%2==1){
                ans=num.substr(0, i+1);
                break;
            }
            i--;
        }
        return ans;
    }
};