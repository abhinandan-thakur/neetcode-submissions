class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if(s.size() == nums.size()) return false;
        return true;
    }
};

/*
sorting is nlogn
a set can do it but it is n space

*/