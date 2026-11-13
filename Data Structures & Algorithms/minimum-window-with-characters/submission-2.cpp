class Solution {
public:
    string minWindow(string s, string t) {
        int missing = t.size();
        vector<int> mp(128, 0);
        for(auto &c: t) mp[c]++;
        int left = 0;
        int bestS = INT_MAX, bestL = 0;
        string ans = s+t;                    
        for(int right = 0; right < s.size(); right++) {
            if(mp[s[right]] > 0) missing--;
            mp[s[right]]--;
            while(missing == 0 && left <= right) {
                if(right-left+1 < bestS) {
                    bestS = right-left+1;
                    bestL = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) missing++;
                left++;
            }
        }
        return (bestS == INT_MAX) ? "" : s.substr(bestL, bestS);
    }
};
