class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxima = 0;
        int minima = 101;
        for(auto price : prices) {
            maxima = max(maxima, price-minima);
            minima = min(minima, price);
        }
        return maxima;
    }
};
