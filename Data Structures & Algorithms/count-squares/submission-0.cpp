class CountSquares {
private:
    unordered_map<int, unordered_map<int,int>> mp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;
        for(auto& [key, val]: mp) {
            int gap = x-key;
            if(!gap) continue;
            ans += val[y]*mp[x][y+gap]*mp[key][y+gap];
            ans += val[y]*mp[x][y-gap]*mp[key][y-gap];
        }
        return ans;
    }
};
