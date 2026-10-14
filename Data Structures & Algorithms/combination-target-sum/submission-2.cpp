#include <vector>
#include <set>
class Solution {
private:
    std::vector <int> nums;
    int target;
    std::set <std::vector <int>> ans;
    void recursion(std::vector<int> &curr, int sum = 0, int start = 0) {
        if(sum == target) {
            ans.insert(curr);
        }
        if(sum >= target) return;
        for(int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            recursion(curr, sum+nums[i], i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        sort(this->nums.begin(), this->nums.end());
        vector<int> curr;
        recursion(curr);
        std::vector<std::vector<int>> output(ans.begin(), ans.end());
        return output;
    }
};
