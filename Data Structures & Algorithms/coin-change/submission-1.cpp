class Solution {
private:
    vector <int> coins;
    map<pair<int,int>, int> mp;
    int recursion(int index, int target) {
        if(target == 0) return 0;
        if(index >= coins.size() || target < 0) return INT_MAX/2;
        if(mp.count({index, target})) return mp[{index, target}];
        int minima = INT_MAX;
        for(int i = index; i < coins.size(); i++) {
            int ret = recursion(i, target-coins[i])+1;
            minima = min(minima, ret);
        }
        return mp[{index, target}] = minima;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        int ans = recursion(0,amount);
        if(ans >= INT_MAX/2) return -1;
        return ans;
    }
};
