class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        for(int i=0;i<word.size();i++){
            if(i>7 && i<=15){
                ans+=2;
            }
            else if(i>15 && i<=23){
                ans+=3;
            }
            else if(i>23 && i<=25){
                ans+=4;
            }
            else{
                ans+=1;
            }
        }
        return ans;
    }
};