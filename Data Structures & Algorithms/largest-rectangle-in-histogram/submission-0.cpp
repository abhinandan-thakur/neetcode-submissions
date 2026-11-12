class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sta;
        int n = heights.size();
        int best = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!sta.empty() && heights[sta.top()] > heights[i]) {
                int h = sta.top();
                sta.pop();
                int left = (sta.empty()) ? -1: sta.top();
                best = max(best, heights[h]*(i-left-1));
            }
            sta.push(i);
        }
        while(!sta.empty()) {
            int h = sta.top();
            sta.pop();
            int left = (sta.empty()) ? -1 : sta.top();
            best = max(best, heights[h]*(n-left-1));
        }
        return best;
    }
};
