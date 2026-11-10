class Solution {
private:
    vector<pair<int,int>> nei = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<int>> dp;
    vector<vector<int>> matrix;
    int m, n;
    int dfs(int row, int col) {
        if(dp[row][col]!=-1) return dp[row][col];
        int length = 1;
        for(auto [dr,dc]: nei) {
            int nr = row+dr;
            int nc = col+dc;
            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if(matrix[nr][nc] <= matrix[row][col]) continue;
            length = max(length, dfs(nr, nc)+1);
        }
        return dp[row][col] = length;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        this->matrix = matrix;
        dp = vector<vector<int>> (m, vector<int>(n, -1));
        int ans = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                ans = max(ans, dfs(row, col));
            }
        }
        return ans;
    }
};
