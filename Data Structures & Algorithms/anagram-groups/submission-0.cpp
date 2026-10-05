class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s : strs) {
            string tmp = s;
            sort(s.begin(), s.end());
            mp[s].push_back(tmp);
        }
        vector<vector<string>> output;
        for(auto [key, val]: mp) {
            output.push_back(val);
        }
        return output;
    }
};
/*
Constraints:

    1 <= strs.length <= 10000.
    0 <= strs[i].length <= 100
    strs[i] is made up of lowercase English letters.
    o(strs*slogs)

*/