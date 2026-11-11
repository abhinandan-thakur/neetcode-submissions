class Solution {
private:
    string s;
    map<pair<int,int>, int> mp;
    bool recursion(int index = 0, int open = 0) {
        if(index >= s.size()) {
            if(open == 0) return true;
            return false;
        }
        if(mp.count({index, open})) return mp[{index, open}];
        bool ans = false;
        if(s[index] == '*') {
            ans = ans || recursion(index+1, open+1);
            ans = ans || recursion(index+1, open);
            ans = ans || recursion(index+1, open-1);
        }
        if(s[index] == '(') ans = ans || recursion(index+1, open+1);
        if(s[index] == ')' && open > 0) ans = ans || recursion(index+1, open-1);
        return mp[{index, open}] = ans;
    }
public:
    bool checkValidString(string s) {
        this->s = s;
        return recursion();
    }
};
