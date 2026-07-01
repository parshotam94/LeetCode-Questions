class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for(int val: bills){
            if(val==5){
                five+=1;
            }
            else if(val==10){
                if(five){
                    five-=1;
                    ten+=1;
                }
                else{
                    return false;
                }
            }
            else{
                if(ten && five){
                    ten-=1;
                    five-=1;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};