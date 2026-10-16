class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> nei = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 0) {
                    q.push({row,col});
                    visited[row][col] = true;
                }
            }
        }
        int distance = 0;
        while (!q.empty()) {
            int level = q.size();
            while(level--) {
                auto [row, col] = q.front(); q.pop();
                grid[row][col] = distance;
                for( auto [dr,dc] : nei) {
                    int nr = dr+row;
                    int nc = dc+col;
                    if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
                    if(visited[nr][nc]) continue;
                    if(grid[nr][nc] == -1) continue;
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                }
            }
            distance++;
        }
    }
};
