class Solution {
private:
public:
    int trap(vector<int>& height) {
        stack<int> sta;
        int area = 0;
        for(int right = 0; right < height.size(); right++) {
            while(!sta.empty() && height[sta.top()] < height[right]) {
                int bottom = height[sta.top()]; sta.pop();
                if(sta.empty()) break;
                int left = sta.top();
                int h = min(height[left], height[right]) - bottom;
                int w = right-left-1;
                area = area+h*w;;
            }
            sta.push(right);
        }
        return area;
    }
};
