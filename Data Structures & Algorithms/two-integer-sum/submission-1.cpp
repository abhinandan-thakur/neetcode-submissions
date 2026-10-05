class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int key = 0; key < nums.size(); key++) {
            int val = nums[key];
            if(mp.count(target-val)) return {mp[target-val], key};
            mp[val] = key;
        }

        return {-1,-1};
    }
};

/*
i can use two pointer
but i think i can use bs too
sort and binary search nlogn
two pointer is n
let us just use hashmap compliment
*/
