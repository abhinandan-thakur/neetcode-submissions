#include <cmath>
#include <queue>
#include <tuple>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<tuple<double,int,int>> pq;
        for(vector<int> &point: points) {
            double x1 = point[0];
            double y1 = point[1];
            double distance = sqrt(x1*x1+y1*y1);
            pq.push({distance,point[0],point[1]});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            vector<int> curr = {get<1>(pq.top()), get<2>(pq.top())};
            ans.push_back(curr);
            pq.pop();
        }
        return ans;
    }
};
