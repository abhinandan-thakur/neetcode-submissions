#include <vector>
class Solution {
private:
    std::vector <std::vector <int>> ans;
    std::vector <int> nums;
    std::vector <int> matcher;
    void recursion(vector<int> &curr) {
        if(nums == matcher) {
            ans.push_back(curr);
            return;
        }
        for(auto &num : nums) {
            if(num == 11) continue;
            int tmp = num;
            curr.push_back(tmp);
            num = 11;
            recursion(curr);
            num = tmp;
            curr.pop_back();
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        matcher = std::vector <int>(nums.size(), 11);
        this->nums = nums;
        std::vector <int> curr;
        recursion(curr);
        return ans;
    }
};
