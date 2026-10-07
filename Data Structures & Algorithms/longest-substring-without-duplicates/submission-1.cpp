class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> existAt;
        int maxima = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            if(existAt.count(s[i])) {
                left = max(left, existAt[s[i]]+1);
            }
            existAt[s[i]] = i;
            maxima = max(maxima, i-left+1);
        }
        return maxima;
    }
};
/*
s may consist of printable ASCII characters.
i can't use bitmask of 26
a set maybe but lets check start with the first var add in set until find duplicate but then where is the location of the duplicate the leftest start froms its index+1
and repeat this process
*/