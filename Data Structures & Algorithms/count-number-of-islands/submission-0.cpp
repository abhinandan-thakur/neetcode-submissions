#include <vector>
class Solution {
private:
    vector<vector<bool>> visited;
    vector<pair<int,int>> nei = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<char>> grid;
    void recursion(int row, int col) {
        visited[row][col] = true;
        for(auto [dr,dc]: nei) {
            int nr = dr+row;
            int nc = dc+col;
            if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
            if(visited[nr][nc]) continue;
            if(grid[nr][nc] != '1') continue;
            recursion(nr,nc);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] != '1') continue;
                if(visited[row][col]) continue;
                recursion(row,col);
                count++;
            }
        }
        return count;
    }
};
