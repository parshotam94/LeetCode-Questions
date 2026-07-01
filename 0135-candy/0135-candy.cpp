class Solution {
public:
    int candy(vector<int>& ratings) {
        // int n=ratings.size();
        // vector<int>left(n, 0), right(n, 0);
        // left[0]=1;
        // right[n-1]=1;
        // for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]=left[i-1]+1;
        //     }
        //     else{
        //         left[i]=1;
        //     }
        // }
        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i]>ratings[i+1]){
        //         right[i]=right[i+1]+1;
        //     }
        //     else{
        //         right[i]=1;
        //     }
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     if(left[i]>=right[i]){
        //         ans+=left[i];
        //     }
        //     else{
        //         ans+=right[i];
        //     }
        // }
        // return ans;

        //slope 
        int sum=1, n=ratings.size(), i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum+=1, i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak+=1, sum+=peak, i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down, i++, down++;
            }
            if(down>peak){
                sum+=down-peak;
            }
        }
        return sum;
    }
};