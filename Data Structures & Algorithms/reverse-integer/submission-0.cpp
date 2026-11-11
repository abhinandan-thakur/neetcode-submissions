class Solution {
public:
    int reverse(int x) {
        long long dup = abs(x);
        long long reverse = 0;
        while(dup) {
            int lastD = dup%10;
            reverse = reverse*10+lastD;
            dup = dup/10;
        }
        if(x < 0) reverse = -reverse;
        if(reverse > INT_MAX || reverse < INT_MIN) return 0;
        return reverse;
    }
};
