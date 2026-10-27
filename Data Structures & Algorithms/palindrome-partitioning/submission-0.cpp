class Solution {
private:
    string s;
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        if(s == "") return false;
        int left = 0, right = s.size()-1;
        while(left < right) {
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        } 
        return true;
    }
    // index is a state, and is palindroem also
    // on each index check whether the string form a pal or not
    // if a pal is formed 2 choices new sub str or same continue
    // if not a pal continue
    void recursion(int index = 0, string current = "", vector<string> v = {}) {
        bool isP = isPalindrome(current);
        // cout << "isP --> " << isP << endl;
        // cout << "curr --> " << current << endl;
        if(index >= s.size()) {
            v.push_back(current);
            if(isP) {
                ans.push_back(v);
                // cout << "v added to ans" << endl;
            }
            // cout << "finish" << endl;
            return;
        }
        // expand
        recursion(index+1, current+s[index], v);
        // start new
        if(isP) {
            v.push_back(current);
            recursion(index+1, string(1, s[index]), v);    
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        recursion();
        return ans;
    }
};
