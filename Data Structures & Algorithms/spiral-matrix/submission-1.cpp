class Solution {
private:
    pair<int,int> newDirection(int dir = 0) {
        switch(dir) {
            case 0: return {0,1};
            case 1: return {1,0};
            case 2: return {0,-1};
            case 3: return {-1,0};
        }
        return {0,1};
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> traversal;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int row = 0;
        int col = 0;
        int dir = 0;
        for(int i = 0; i < m*n; i++) {
            traversal.push_back(matrix[row][col]);
            visited[row][col] = true;
            auto [dr,dc] = newDirection(dir);
            int nr = row+dr;
            int nc = col+dc;
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
                dir = (dir+1)%4;
                tie(dr,dc) = newDirection(dir);
            }
            row += dr;
            col += dc;
        }
        return traversal;
    }
};
