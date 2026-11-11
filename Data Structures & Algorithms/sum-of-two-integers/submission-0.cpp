class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int carry = (a & b) << 1;
            a = a^b;
            b = carry;
        }
        return a;
    }
    // so we have to do this in binary
    // what is 4 | 5? 9 = 10001
    // 100
    // 101
    // 101
    // take last digit of both have a carry and or operator used
    // right shift both and left shift the ans but that gave ans in reverse lets try
    // 100, 101
    // ifboth 1 have a carry in this case nop
    // 1 , 10, 10
    // 10, 1, 1
    // 1001 but this was a palindrome lets tray again
    // 5 -> 101, 1 -> 001, 6 -->110
    // 0, 10, 00, carry = 1
    // 01, 1, 0
    // 011

    
};
