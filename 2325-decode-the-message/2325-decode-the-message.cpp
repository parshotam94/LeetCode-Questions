class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char>mpp;
        string str="";
        int i=0;
        for(char ch: key){
            if(ch==' ') continue;
            if(mpp.find(ch)==mpp.end()){
                mpp[ch]='a'+i;
                i++;
            }
        }
        for(char ch: message){
            if(ch==' ') str+=' ';
            else str+=(mpp[ch]);
        }
        return str;
    }
};