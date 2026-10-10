class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> unique;
        for(int i = 0; i < nums.size(); i++) {
            if(unique.count(nums[i])) return nums[i];
            unique.insert(nums[i]);
        }
        return -1;
    }
};
