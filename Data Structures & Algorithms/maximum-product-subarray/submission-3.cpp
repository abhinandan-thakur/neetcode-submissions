class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0], maxMax = nums[0];
        int currMin = nums[0], minMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) swap(currMin, currMax);
            currMax = max(nums[i], currMax*nums[i]);
            currMin = min(nums[i], currMin*nums[i]);
            maxMax = max(currMax, maxMax);
            minMin = min(currMin, minMin);
        }
        return maxMax;
    }
};
