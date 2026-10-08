class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*prev(s.end()));
        for(int i = k; i < nums.size(); i++) {
            int left = i-k;
            s.erase(s.find(nums[left]));
            s.insert(nums[i]);
            ans.push_back(*prev(s.end()));
        }
        return ans;
    }
};
