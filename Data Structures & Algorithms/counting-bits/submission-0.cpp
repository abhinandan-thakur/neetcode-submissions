class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        vector<int> ans(n+1, 0);
        ans[0] = 0;
        ans[1] = 1;
        for(int b = 2; b <= n; b++) {
            ans[b] = ans[b>>1]+(b&1);
        }
        return ans;
    }
};

/*
0 - 0 - 0
1 - 1 - 1
2 - 1 - 10
3 - 2 - 11
4 - 1 - 100
5 - 2
6 - 2

*/