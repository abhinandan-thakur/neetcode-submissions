#include <vector>
#include <set>
class Solution {
private:
    std::vector <int> nums;
    std::set <std::vector <int>> s;
    void recursion(std::vector <int> curr = {},int start = 0) {
        s.insert(curr);
        if(start >= nums.size()) return;
        for(int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            recursion(curr, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        recursion();
        return std::vector <std::vector <int>> (s.begin(), s.end());
    }
};
