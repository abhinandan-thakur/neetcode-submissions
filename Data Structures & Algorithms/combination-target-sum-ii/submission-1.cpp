#include <vector>
class Solution {
private:
    vector<vector<int>> ans;
    int target;
    void recursion(std::vector <int> &candidates, vector<int> &curr, int sum = 0, int start = 0) {
        if(sum == target) ans.push_back(curr);
        if(sum >= target) return;
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1]) continue;
            if(sum+candidates[i] > target) break;
            curr.push_back(candidates[i]);
            recursion(candidates, curr, sum+candidates[i], i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        recursion(candidates, curr);
        return ans;
    }
};
