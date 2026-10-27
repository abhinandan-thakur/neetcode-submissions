class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> frequency;
        int left = 0, maxima = 0, result = 0;
        for(int right = 0; right < s.size(); right++) {
            frequency[s[right]]++;
            maxima = max(maxima, frequency[s[right]]);
            while((right-left+1) - maxima > k) {
                frequency[s[left]]--;
                left++;
            }
            result = max(result, right-left+1);
        }
        return result;
    }
};
