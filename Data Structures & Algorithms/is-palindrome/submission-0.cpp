class Solution {
public:
    bool isPalindrome(string s) {
        string trimmed;
        for(int i = 0; i < s.size(); i++) {
            if(!(isalpha(s[i]) || isdigit(s[i]))) continue;
            trimmed += tolower(s[i]);
        }
        int left = 0;
        int right = trimmed.size()-1;
        // cout << trimmed << endl;
        while(left <= right) {
            if(trimmed[left] != trimmed[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
/*
first store s in a string only the values we need...
then there are two approch for palindrome start from the middle to outwards
its tc is idk
take two stacks? for palindrome
its tc is n
*/