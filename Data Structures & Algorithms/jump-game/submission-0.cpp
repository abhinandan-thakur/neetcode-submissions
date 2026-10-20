class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        for(int i = 0; i <= limit && i < nums.size(); i++) {
            if(i+1 == nums.size()) return true;
            limit = max(limit, i+nums[i]);
        }
        return false;
    }
};
