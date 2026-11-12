class Solution {
private:
    map<pair<int,int>, bool> mp;
    string s, p;
    bool recursion(int indexS, int indexP) {
        if(indexP >= p.size()) return indexS == s.size();
        if(mp.count({indexS, indexP})) return mp[{indexS, indexP}];
        bool curr = indexS < s.size() && (s[indexS] == p[indexP] || p[indexP] == '.');
        bool ans = false;
        if(indexP+1 < p.size() && p[indexP+1] == '*') {
            ans =  recursion(indexS, indexP+2) || (curr && recursion(indexS+1, indexP));
        }
        else ans = curr && recursion(indexS+1, indexP+1);

        return mp[{indexS, indexP}] = ans;
    }
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        return recursion(0,0);
    }
};
