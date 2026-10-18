#include <cstring>
class Solution {
private:
    int dp[5001][2];
    vector<int> prices;
    int recursion(int day = 0, bool canBuy = true) {
        if(day >= prices.size()) return 0;
        if(dp[day][canBuy] != -1) return dp[day][canBuy];
        int buy = 0, skip = 0, sell = 0;
        if(canBuy) buy += recursion(day+1, false) - prices[day];
        else if(!canBuy) sell += recursion(day+2, true) + prices[day];
        skip += recursion(day+1, canBuy);
        return dp[day][canBuy] = max({buy, sell, skip});
    }
public:
    int maxProfit(vector<int>& prices) {
        this->prices = prices;
        memset(dp, -1, sizeof(dp));
        return recursion();
    }
};
