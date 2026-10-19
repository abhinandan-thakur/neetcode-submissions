class Solution {
private:
    int n;
    vector<int> nums;
    map<pair<int,int>, int> cache;
    int recursion(int index, int target) {
        if(index == n && target == 0) return 1;
        if(index == n) return 0;
        if(cache.count({index, target})) return cache[{index, target}];
        int add = 0, sub = 0;
        add += recursion(index+1, target-nums[index]);
        sub += recursion(index+1, target+nums[index]);
        return cache[{index, target}] = add+sub; 
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        this->nums = nums;
        return recursion(0, target);
    }
};
/*
no repetition first of all is allowed
after taking one move to the next index
at each step we can add or subtract
classic take skip dp
but what about prefix dp or suffix dp is it possible?
i am not finding anything 
btw can we use digit dp each digit can be converted into 
miuns or positive but that is not digit dp in true sense 
let just write code...
states = index, sum

// i use a map because target is from (-1000, 1000) i don't want to deal with idnex shifting etc...
*/

