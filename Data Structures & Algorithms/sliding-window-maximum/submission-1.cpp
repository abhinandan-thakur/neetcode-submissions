class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<int> s;
        unordered_map<int,int> freq;
        for(int i = 0; i < k; i++) {
            s.insert(nums[i]);
            freq[nums[i]]++;
        }
        vector<int> ans;
        ans.push_back(*prev(s.end()));
        for(int i = k; i < nums.size(); i++) {
            int left = i-k;
            if(freq[nums[left]] == 1) s.erase(nums[left]);
            freq[nums[left]]--;
            s.insert(nums[i]);
            freq[nums[i]]++;
            ans.push_back(*prev(s.end()));
        }
        return ans;
    }
};
