class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxima = 0;
        int minima = prices[0];
        for(int price : prices) {
            maxima = max(maxima, price-minima);
            minima = min(minima, price);
        }
        return maxima;
    }
};
