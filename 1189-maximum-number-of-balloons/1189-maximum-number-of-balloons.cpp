class Solution {
public:
    int maxNumberOfBalloons(string text) {

        unordered_map<char,int> mpp;

        for(char ch:text){

            if(ch=='b' || ch=='a' || ch=='l' ||
               ch=='o' || ch=='n'){

                mpp[ch]++;
            }
        }

        vector<int> values;

        string txt="balon";

        for(char ch:txt){

            if(mpp.find(ch)==mpp.end()){

                return 0;
            }

            if(ch=='l' || ch=='o'){

                values.push_back(mpp[ch]/2);
            }

            else{

                values.push_back(mpp[ch]);
            }
        }

        return *min_element(values.begin(),values.end());
    }
};