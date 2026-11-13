class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int> mp;
        for(auto &h: hand) mp[h]++;
        for(auto [key, val]: mp) {
            if(val == 0) continue;
            for(int i = 0; i < groupSize; i++) {
                if(!mp.count(key+i)) return false;
                if(mp[key+i] < val) return false;
                mp[key+i] -= val;
            }
        }
        return true;
    }
};
