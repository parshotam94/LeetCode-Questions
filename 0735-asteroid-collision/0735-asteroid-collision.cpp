class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int val=asteroids[i];
            if(val>0){
                st.push(val);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(val)){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(val)){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top()<0){
                        st.push(val);
                    }
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};