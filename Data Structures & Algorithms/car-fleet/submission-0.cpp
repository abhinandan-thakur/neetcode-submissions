class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v(position.size(), {0,0});
        for(int i = 0; i < v.size(); i++) v[i] = {position[i], speed[i]};
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });
        int fleet = 0;
        double time = 0.0;
        double lastTime = 0.0;

        for(int index = 0; index < v.size(); index++) {
            double time = (double)(target-v[index].first)/v[index].second;
            if(time > lastTime) {
                fleet++;
                lastTime = time;
            }
        }
        return fleet;
    }
};
