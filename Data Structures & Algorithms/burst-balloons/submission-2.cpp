class Solution {
private:
    vector<vector<int>> dp;
    vector<int> nums;
    int recursion(int left, int right) {
        if(right-left < 2) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        int ans = 0;
        for(int center = left+1; center < right; center++) {
            ans = max(ans, recursion(left, center)+recursion(center, right)+nums[left]*nums[center]*nums[right]);
        }
        return dp[left][right] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size()+2, 1);
        dp = vector<vector<int>>(nums.size()+2, vector<int>(nums.size()+2, -1));
        for(int i = 1; i < arr.size()-1; i++) arr[i] = nums[i-1];
        this->nums =arr;
        return recursion(0, arr.size()-1);
    }
};
