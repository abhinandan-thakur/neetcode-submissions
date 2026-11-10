#include <cstring>
class Solution {
private:
    string s;
    vector<string> wordDict;
    int dp[201];
    bool recursion(int index) {
        if(index == s.size()) return true;
        if(dp[index] != -1) return dp[index];
        bool ans = false;
        for(auto &word: wordDict) {
            int size = word.size();
            string tmp = s.substr(index, size);
            if(tmp == word) {
                ans = ans || recursion(index+size);
            }
        }
        return dp[index] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        this->wordDict = wordDict;
        memset(dp, -1, sizeof(dp));
        return recursion(0);
    }
};
