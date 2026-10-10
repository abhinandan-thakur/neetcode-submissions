class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v(position.size(), {0,0});
        for(int index = 0; index < position.size(); index++) v[index] = {position[index], speed[index]};
        sort(v.begin(), v.end(), [](const auto &a, const auto &b){
            return a.first > b.first;
        });
        int fleet = 0;
        double time = 0.0, lastTime = 0.0;
        for(int i = 0; i < v.size(); i++) {
            time = (double)(target-v[i].first)/v[i].second;
            if(time > lastTime) {
                fleet++;
                lastTime = time;
            }
        }
        return fleet;
    }
};
