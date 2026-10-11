class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> a,b;
        if(s1 == s2) return true;
        if(s1.size()<s2.size()) swap(s1,s2);
        string t;
        for(auto c : s1){
            if(c!=' ')t.push_back(c);
            else a.push_back(t),t="";
        }
        a.push_back(t);
        t="";
        for(auto c : s2){
            if(c!=' ')t.push_back(c);
            else b.push_back(t),t="";
        }
        b.push_back(t);
        int i = 0 ;
        while(i<b.size() and a[i]==b[i])i++;
        int j = b.size()-1,k = a.size()-1;
        while(j>=i and b[j]==a[k]){j--;k--;}
        if(k-i+1 == a.size()-b.size())return true;
        return false;
    }
};