class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = -10000, maxSum = -10000;
        for(int i = 0; i < nums.size(); i++) {
            currSum = max(nums[i], currSum+nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
