class Solution {
private:
    string s;
    vector<int> dp;
    int recursion(int index = 0) {
        if(index >= s.size()) return 1;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];
        int res = recursion(index+1);
        if(index+1 < s.size() && (s[index] == '1' || (s[index] == '2' && s[index+1] < '7'))) {
            res += recursion(index+2);
        }
        return dp[index] = res;
    }
public:
    int numDecodings(string s) {
        this->s = s;
        dp = vector<int>(s.size(), -1);
        return recursion();
    }
};
