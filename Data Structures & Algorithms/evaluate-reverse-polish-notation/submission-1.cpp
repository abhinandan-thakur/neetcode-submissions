class Solution {
private:
    int eval(int a, int b, string oper) {
        if(oper == "+") return a+b;
        if(oper == "-") return a-b;
        if(oper == "/") return a/b;
        return a*b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> number;
        int sum = 0;
        for(int i = 0; i < tokens.size(); i++) {
            string curr = tokens[i];
            if(curr == "+" || curr == "-" || curr == "/" || curr == "*") {
                int b = number.top(); number.pop();
                int a = number.top(); number.pop();
                number.push(eval(a, b, curr));
            }
            else {
                number.push(stoi(curr));
            }
        }
        return number.top();
    }
};
