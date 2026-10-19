class Solution {
public:
    int hammingWeight(uint32_t n) {
        string binary = "";
        while(n > 0) {
            binary += (n%2)+'0';
            n = n/2;
        }
        int count = 0;
        for(auto bin : binary) if(bin == '1') count++;
        return count;
    }
};
