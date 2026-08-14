class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int thirdprev=0, secondprev=1, prev=1;
        for(int i=3;i<=n;i++){
            int curr=thirdprev+secondprev+prev;
            thirdprev=secondprev;
            secondprev=prev;
            prev=curr;
        }
        return prev;
    }
};