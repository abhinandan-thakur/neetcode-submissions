class Solution {
private:
    vector<vector<int>> dp;
    vector<int> a;
    int recursion(int l, int r) {
        if(r-l<2) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int best = 0;
        for(int k = l+1; k < r; k++) {
            best = max(best, recursion(l, k) + recursion(k, r) + a[l]*a[k]*a[r]);
        }
        return dp[l][r] = best;
    }
public:
    int maxCoins(vector<int>& nums) {
        a = vector<int>(nums.size()+2, 1);
        for(int i = 0; i < nums.size(); i++) a[i+1] = nums[i];
        dp = vector<vector<int>>(nums.size()+2, vector<int>(nums.size()+2, -1));
        return recursion(0, nums.size()+1);
    }
};
