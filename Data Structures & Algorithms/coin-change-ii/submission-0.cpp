class Solution {
private:
    int n;
    vector<int> coins;
    vector<vector<int>> cache;
    int recursion(int index, int amount) {
        if(amount == 0) return 1;
        if(amount <= 0) return 0;
        if(cache[index][amount] != -1) return cache[index][amount];
        int ans = 0;
        for(int start = index; start < n; start++) {
            ans += recursion(start, amount-coins[start]);
        }
        return cache[index][amount] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        this->coins = coins;
        cache = vector<vector<int>> (n, vector<int>(amount+1, -1));
        // cout << "lgtm" << endl;
        return recursion(0, amount);
    }
};
