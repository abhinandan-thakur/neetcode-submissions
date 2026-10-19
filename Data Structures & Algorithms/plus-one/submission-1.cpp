class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for(int i = 0; i < digits.size(); i++) num = num*10+digits[i];
        cout << num << endl;

        num++;
        cout << num << endl;
        vector<int> ans;
        while(num!=0) {
            int lastDigit = num%10;
            ans.push_back(lastDigit);
            num = num/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
