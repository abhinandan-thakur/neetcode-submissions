class Solution {
private:
    string s, p;
    map<pair<int,int>, bool> mp;
    bool recursion(int index1, int index2) {
        if(index2 >= p.size()) return index1 == s.size();
        if(mp.count({index1, index2})) return mp[{index1, index2}];
        bool curr = index1 < s.size() && ((s[index1] == p[index2]) || (p[index2] == '.'));
        bool ans = false;
        if(index2+1 < p.size() && p[index2+1] == '*') ans = (recursion(index1, index2+2) || curr && recursion(index1+1, index2));
        else ans = curr && recursion(index1+1, index2+1);
        return mp[{index1, index2}] = ans;
    }
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        return recursion(0,0);
    }
};
