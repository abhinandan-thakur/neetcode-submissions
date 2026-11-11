class Solution {
private:
    vector<vector<int>> dp;
    string s;
    string t;
    int recursion(int index1 = 0, int index2 = 0) {
        if(index2 >= t.size()) return 1;
        if(index1 >= s.size()) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        int cnt = 0;
        //skip
        cnt += recursion(index1+1, index2);
        //take
        if(s[index1] == t[index2]) {
            cnt += recursion(index1+1, index2+1);
        }
        return dp[index1][index2] = cnt;
    }
public:
    int numDistinct(string s, string t) {
        dp = vector<vector<int>>(s.size(), vector<int>(t.size(), -1));
        this->s = s;
        this->t = t;
        return recursion();
    }
};
