class Solution {
private:
    string combined = "";
public:
    string encode(vector<string>& strs) {
        for(auto str : strs) {
            int length = str.size();
            combined += to_string(length);
            combined += ":";
            combined += str;
        }
        return combined;
    }
    vector<string> decode(string s) {
        vector<string> output;
        int i = 0;
        while(i < s.size()) {
            int number = 0;
            string num = "";
            while( i < s.size() && s[i] != ':') {
                num += s[i];
                i++;
            }
            number = stoi(num);
            // we are at :
            i++;
            output.push_back(s.substr(i, number));
            i = i+number;
        }
        return output;
    }
};
