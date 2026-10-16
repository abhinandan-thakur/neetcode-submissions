class Solution {
private:
    int palindromes = 0;
    string s;
    void recursion(int leftIndex = 0, int rightIndex = 0) {
        if(leftIndex < 0 || rightIndex >= s.size()) return;
        if(s[leftIndex] != s[rightIndex]) return;
        palindromes++;
        recursion(leftIndex-1, rightIndex+1);
    }
public:
    int countSubstrings(string s) {
        this->s = s;
        for(int index = 0; index < s.size(); index++) {
            recursion(index, index);
            recursion(index-1, index);
        }
        return palindromes;
    }
};
