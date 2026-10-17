#include <cstring>
class Solution {
private:
    int totalSum;
    vector <int> nums;
    // memoization;
    int dp[101][101*50];
    bool recursion(int index = 0, int sum = 0) {
        if(dp[index][sum] != -1) return dp[index][sum];
        if(sum == (totalSum-sum)) return true;
        // only positive no negative numbers
        if(sum > (totalSum-sum)) return false;
        if(index>=nums.size()) return false;
        // now take or skip
        bool take = recursion(index+1, sum+nums[index]);
        bool skip = recursion(index+1, sum);
        return dp[index][sum] = (take||skip);
    }
public:
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        memset(dp, -1, sizeof(dp));
        // -1 init, 0 false, 1 true i guess int dp will work
        return recursion();
    }
};
