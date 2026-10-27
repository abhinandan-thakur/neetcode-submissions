class Solution {
private:
    set<string> perm;
    void recursion(int open, int close, int isOpened = 0, string res = "") {
        if(open == 0 && close == 0 && isOpened == 0) {
            perm.insert(res);
            return;
        }
        if(open > 0) recursion(open-1, close, isOpened+1, res+"(");
        if(close > 0 && isOpened > 0) recursion(open, close-1, isOpened-1, res+")");
    } 
public:
    vector<string> generateParenthesis(int n) {
        recursion(n,n);
        vector<string> ans(perm.begin(), perm.end());
        return ans;
    }
};
