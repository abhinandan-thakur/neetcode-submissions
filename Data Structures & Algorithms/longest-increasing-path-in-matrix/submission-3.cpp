class Solution {
private:
    vector<pair<int,int>> nei = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> matrix;
    int dfs(int row, int col) {
        if(dp[row][col] != -1) return dp[row][col];
        int len = 0;
        for(auto [dr, dc]: nei) {
            int nr = dr + row;
            int nc = dc + col;
            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if(matrix[nr][nc] <= matrix[row][col]) continue;
            len = max(len, dfs(nr, nc));
        }
        return dp[row][col] = len+1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        this->matrix = matrix;
        int maxima = 0;
        dp = vector<vector<int>> (m, vector<int>(n, -1));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dp[i][j] != -1) continue;
                maxima = max(maxima, dfs(i,j));
            }
        }
        return maxima;
    }
};
