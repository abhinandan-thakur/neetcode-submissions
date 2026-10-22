class LRUCache {
private:
    vector<pair<int,int>> cache;
    int sizeCap;
public:
    LRUCache(int capacity) {
        sizeCap = capacity;
    }
    
    int get(int key) {
         for(int i = 0; i < cache.size(); i++) {
            if(cache[i].first == key) {
                pair<int,int> tmp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(tmp);
                return tmp.second;
            }
         }
         return -1;
    }
    
    void put(int key, int value) {
        for(int i = 0; i < cache.size(); i++) {
            if(cache[i].first == key) {
                cache.erase(cache.begin()+i);
                break;
            }
        }
        if(cache.size() == sizeCap) cache.erase(cache.begin());
        cache.push_back({key, value});
    }
};
