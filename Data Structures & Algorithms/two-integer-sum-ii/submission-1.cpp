class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < numbers.size(); i++) {
            int index = i+1;
            if(mp.count(target-numbers[i]) && (mp[target-numbers[i]] != index)) {
                return {mp[target-numbers[i]], index};
            }
            // index is is 1-indexed
            mp[numbers[i]] = index;
        }
        return {-1,-1};
    }
};
