class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num1.size();
        int m = num2.size();
        vector<int> answer(n+m, 0);
        for(int i = num1.size()-1; i >= 0; i--) {
            for(int j = num2.size()-1; j >= 0; j--){
                int a = num1[i]-'0';
                int b = num2[j]-'0';
                int product = a*b+answer[i+j+1];
                answer[i+j+1] = product%10;
                answer[i+j] += product/10;
            }
        }
        string ans = "";
        int i = 0;
        for(; i < answer.size(); i++) {
            if(answer[i] != 0) break;
        }
        for(;i < answer.size(); i++) {
            ans += to_string(answer[i]);
        }
        return ans;
    }
};
