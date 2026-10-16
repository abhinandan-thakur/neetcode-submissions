class Solution {
private:
    vector<int> nums;
    int maxima(int start, int end) {
        int a = nums[start], b = max(nums[start], nums[start+1]);
        for(int i = start+2; i <= end; i++) {
            int c = max(a+nums[i], b);
            a = b;
            b = c;
        }
        return max(a,b);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        this->nums = nums;
        return max(maxima(0,nums.size()-2), maxima(1,nums.size()-1));
    }
};
/*
I thnk i need to think
1. take skip dp i can make recursion
2. prefix dp
3. digit dp
*/