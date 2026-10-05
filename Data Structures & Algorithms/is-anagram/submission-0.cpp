class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mps, mpt;
        for(auto c : s) mps[c]++;
        for(auto c : t) mpt[c]++;
        if(mps == mpt) return true;
        return false;
    }
};
