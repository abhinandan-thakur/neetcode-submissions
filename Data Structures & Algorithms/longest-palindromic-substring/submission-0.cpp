class Solution {
private:
    string s;
    tuple<int,int,int> recursion(int leftIndex, int rightIndex) {
        if(leftIndex < 0 || rightIndex >= s.size()) return {0, leftIndex+1, rightIndex-1};
        if(s[leftIndex] != s[rightIndex]) return {0, leftIndex+1, rightIndex-1};
        int count = (leftIndex == rightIndex) ? 1 : 2;
        auto [cnt, left, right] = recursion(leftIndex-1, rightIndex+1);
        return {cnt+count, left, right};

    }
public:
    string longestPalindrome(string s) {
        this->s = s;
        int left = 0, right = 0, length = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd
            auto [olen, oleft, oright] = recursion(i, i);
            // even
            auto [elen, eleft, eright] = recursion(i-1, i);
            if (olen > length) {
                length = olen;
                left = oleft;
                right = oright;
            }
            if (elen > length) {
                length = elen;
                left = eleft;
                right = eright;
            }
        }
        return s.substr(left, length);
    }
};
