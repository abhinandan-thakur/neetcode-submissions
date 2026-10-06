class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_map<int,int> indexOf;
        for(int i = 0; i < nums.size(); i++) indexOf[nums[i]] = i;
        set<vector<int>> toPreventDuplicate;
        vector<vector<int>> ans;
        int j = 1;
        for(int i = 0; i < nums.size() && i < j; i++) {
            for(j = i+1; j < nums.size(); j++) {
                int sum = nums[i]+nums[j];
                if(s.count(-sum)) {
                    if(indexOf[-sum] == i || indexOf[-sum] == j) continue;
                    vector<int> tmp = {nums[i], nums[j], -sum};
                    sort(tmp.begin(), tmp.end());
                    if(toPreventDuplicate.count(tmp)) continue;
                    toPreventDuplicate.insert(tmp);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
/*
constraints are low i can go n3 but this can be done in at least n2?

Explanation: The only possible triplet sums up to 0.

Constraints:

    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5



nums0 + nums1 + nums2 = target
nums1+nums2 = target-nums0
target is 0 so nums0+nums1 = -nums2;

*/