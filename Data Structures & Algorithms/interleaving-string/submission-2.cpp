class Solution {
private:
    string s1, s2, s3;
    vector<vector<int>> dp;
    bool recursion(int index1 = 0, int index2 = 0) {
        int index3 = index1+index2;
        if(index1==s1.size() && index2==s2.size() && index3==s3.size()) return true;
        if(index3==s3.size()) return false;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        bool ans = false;
        if(s1[index1] == s3[index3] && s2[index2] == s3[index3]) ans = recursion(index1+1, index2) || recursion(index1, index2+1);
        else if(s1[index1] == s3[index3]) ans = recursion(index1+1, index2);
        else if(s2[index2] == s3[index3]) ans = recursion(index1, index2+1);
        return dp[index1][index2] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        dp = vector<vector<int>> (s1.size()+1, vector<int>(s2.size()+1, -1));
        return recursion();
    }
};
