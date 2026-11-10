class Solution {
private:
    string text1;
    string text2;
    map<pair<int,int>, int> cache;
    int recursion(int index1 = 0, int index2 = 0) {
        if(index1 >= text1.size() || index2 >= text2.size()) return 0;
        if(cache.count({index1, index2})) return cache[{index1, index2}];
        if(text1[index1] == text2[index2]) return cache[{index1, index2}] = recursion(index1+1, index2+1)+1;
        return cache[{index1, index2}] = max(recursion(index1+1, index2), recursion(index1, index2+1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;
        return recursion();
    }
};
