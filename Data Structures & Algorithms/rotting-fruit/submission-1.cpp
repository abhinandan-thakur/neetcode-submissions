class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int,int>> shouldBeEmpty;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<pair<int,int>> nei = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(!grid[row][col]) continue;
                else if(grid[row][col] == 1) shouldBeEmpty.insert({row,col});
                else {
                    shouldBeEmpty.insert({row,col});
                    q.push({row,col});
                    visited[row][col] = true;
                }
            }
        }
        int time = -1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [row, col] = q.front(); q.pop();
                shouldBeEmpty.erase({row,col});
                for(auto [dr,dc] : nei) {
                    int nr = dr + row;
                    int nc = dc + col;
                    if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
                    if (visited[nr][nc]) continue;
                    if (grid[nr][nc] != 1) continue;
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
            time++;
        }
        if (time == -1 && shouldBeEmpty.size() == 0) return 0;
        else if (shouldBeEmpty.size() == 0) return time;
        return -1;
    }
};
