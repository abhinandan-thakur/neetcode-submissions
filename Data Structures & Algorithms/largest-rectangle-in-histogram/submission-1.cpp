class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sta;
        int ans = 0;
        for(int right = 0; right <= heights.size(); right++) {
            int curr = (right == heights.size()) ? 0: heights[right];
            while(!sta.empty() && heights[sta.top()] > curr){
                int h = heights[sta.top()]; sta.pop();
                int left = (sta.empty()) ? -1: sta.top();
                int w = right-left-1;
                ans = max(ans, h*w);
            }
            sta.push(right);
        }
        return ans;
    }
};
