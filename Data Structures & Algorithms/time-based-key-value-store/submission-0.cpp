class TimeMap {
private:
    unordered_map<string, set<int>> mp1;
    map<pair<string, int>, string> mp2;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp1[key].insert(timestamp);
        mp2[{key, timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        auto &s = mp1[key];
        auto it = s.upper_bound(timestamp);
        if(it == s.begin()) return "";
        it--;
        return mp2[{key, *it}];
    }
};
