#include <vector>
class Solution {
private:
    std::vector <std::vector <int> > output;
    std::vector <int> nums;
    void recursion(std::vector <int> curr = {}, int start = 0) {
        output.push_back(curr);
        if (start>=nums.size()) return;
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            recursion(curr, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums =nums;
        recursion();
        return output;
    }
};
