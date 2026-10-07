class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> hash(26,0);
        vector<int> matcher(26,0);
        for(char s : s1) matcher[s-'a']++;
        for(int i = 0; i < s1.size(); i++) hash[s2[i]-'a']++;
        if(hash == matcher) return true;
        for(int j = s1.size(); j < s2.size(); j++) {
            hash[s2[j]-'a']++;
            hash[s2[j-s1.size()]-'a']--;
            if(hash == matcher) return true;
        }
        return false;
    }
};
