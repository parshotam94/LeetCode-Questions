class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<pair<int,int>> events;

        for(auto &trip : trips){
            events.push_back({trip[1], +trip[0]}); // pickup
            events.push_back({trip[2], -trip[0]}); // drop
        }

        sort(events.begin(), events.end(),
             [](auto &a, auto &b){
                 if(a.first == b.first)
                     return a.second < b.second; // negative (drop) before positive (pickup)
                 return a.first < b.first;
             });

        int passengers = 0;

        for(auto &event : events){
            passengers += event.second;
            if(passengers > capacity)
                return false;
        }

        return true;
    }
};