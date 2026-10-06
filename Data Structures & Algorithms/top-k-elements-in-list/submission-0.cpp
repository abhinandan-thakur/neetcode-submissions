class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int hash[2001] = {};
        for(int i = 0; i < nums.size(); i++) hash[nums[i]+1000]++;
        priority_queue<pair<int,int>> pq;
        // maxheap
        for(int i = 0; i < 2001; i++) {
            pq.push({hash[i], i});
        }
        vector<int> ans;
        while(k > 0) {
            ans.push_back(pq.top().second-1000);
            pq.pop();
            k--;
        }
        return ans;
    }
};

/*
-1000 <= nums[i] <= 1000

*/
