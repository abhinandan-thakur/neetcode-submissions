class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> ans(temperatures.size(), 0);
        stack <int> sta;
        for(int i = 0; i < temperatures.size(); i++) {
            while(!sta.empty() && temperatures[sta.top()] < temperatures[i]) {
                int val = i-sta.top();
                ans[sta.top()] = val;
                sta.pop();
            }
            sta.push(i);
        }
        return ans;
    }
};
