class Solution {
    vector<vector<char>> letters = {{' '}, {}, {'a', 'b', 'c'}, {'d','e', 'f'}, 
                                    {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
                                    {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w','x','y','z'}};
    vector<string> output;
    string digits;
    void recursion(int index = 0, string curr = "") {
        if(index >= digits.size()) {
            output.push_back(curr);
            return;
        }
        int now = digits[index]-'0';
        vector<char> let = letters[now];
        for(auto c: let) recursion(index+1, curr+c);
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return {};
        this->digits = digits;
        recursion();
        return output;
    }
};
