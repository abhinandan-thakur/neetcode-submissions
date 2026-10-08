class Solution {
private:
    bool isValid(char opening, char closing) {
        if (opening == '(' && closing == ')') return true;
        else if (opening == '[' && closing == ']') return true;
        else if (opening == '{' && closing == '}') return true;
        return false;
    }
public:
    bool isValid(string s) {
        stack <char> sta;
        for(int i = 0; i < s.size(); i++) {
            char curr = s[i];
            if(curr == '(' || curr == '[' || curr == '{') {
                sta.push(curr);
            }
            else {
                if(sta.empty()) return false;
                bool ret = isValid(sta.top(), curr);
                if(ret) sta.pop();
                else return false;
            }
        }
        if(sta.empty()) return true;
        return false;
    }
};
