class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int alice=capacityA;
        int bob=capacityB;
        int n=plants.size();
        int i=0,j=n-1;
        int ca=0,cb=0;
        while(i<=j){
            if(i==j){
                int maxi=max(capacityA,capacityB);
                if(plants[i]>maxi) ca++;
                else break;
                break;
            }
            if(plants[i]>capacityA){
                ca+=1;
                capacityA=alice-plants[i];
            }
            else capacityA=capacityA-plants[i];
            if(plants[j]>capacityB){
                cb+=1;
                capacityB=bob-plants[j];
            }
            else capacityB=capacityB-plants[j];
            i++;j--;
        }
        return ca+cb;
    }
};