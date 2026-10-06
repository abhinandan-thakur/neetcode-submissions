class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxima = 0;
        int minima = INT_MAX/2;
        for(auto price : prices) {
            maxima = max(maxima, price-minima);
            minima = min(minima, price);
        }
        return maxima;
    }
};
