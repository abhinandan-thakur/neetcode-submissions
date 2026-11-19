class Solution {
public:
    string minWindow(string s, string t) {
        int size = t.size();
        if(size > s.size()) return "";
        unordered_map<char,int> tCount;
        for(auto c: t) tCount[c]++;
        int left = 0;
        int l,r;
        l = r = -1;
        for(int right = 0; right < s.size(); right++) {
            if(tCount.count(s[right])) {
                if(tCount[s[right]] > 0) size--;
                tCount[s[right]]--;
            }
            while(size == 0) {
                if(tCount.count(s[left])) {
                    tCount[s[left]]++;
                    if(tCount[s[left]] > 0) size++;
                }
                if(l == -1 || r == -1 || right-left+1 < r){
                    l = left;
                    r = right-left+1;
                }
                left++;
            }
        }
        if(l==-1 || r == -1) return "";
        return s.substr(l, r);
    }
};
