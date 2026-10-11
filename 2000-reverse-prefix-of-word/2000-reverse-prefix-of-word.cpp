class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0, j=0, n=word.length();
        for(char c: word){
            if(c==ch) break;
            else j++;
        }
        if(j==0 || j==n) return word;
        while(i<j){
            swap(word[i], word[j]);
            i++, j--;
        }
        return word;
    }
};