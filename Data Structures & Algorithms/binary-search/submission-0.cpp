class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it =  lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end()) return -1;
        int index = it-nums.begin();
        if(nums[index] != target) return -1;
        return index; 
    }
};
