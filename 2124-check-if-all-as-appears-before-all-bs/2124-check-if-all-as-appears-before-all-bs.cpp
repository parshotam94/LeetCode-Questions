class Solution {
public:
    bool checkString(string s) {
        bool appeared=false;
        for(char ch: s){
            if(ch=='b'){
                appeared=true;
            }
            else if(appeared && ch=='a') return false;
        }
        return true;
    }
};