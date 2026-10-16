#include <vector>
class Solution {
private:
    int RL, CL;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    vector<pair<int,int>> nei = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int recursion(int row, int col) {
        visited[row][col] = true;
        int count = 0;
        for(auto [dr,dc]: nei) {
            int nr = dr+row;
            int nc = dc+col;
            if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;
            if(visited[nr][nc]) continue;
            if(grid[nr][nc] != 1) continue;
            count += recursion(nr,nc)+1;
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        RL = grid.size();
        CL = grid[0].size();
        visited = vector<vector<bool>>(RL, vector<bool>(CL, false));
        int area = 0;
        for(int row = 0; row < RL; row++) {
            for(int col = 0; col < CL; col++) {
                // cout << "fda" << endl;
                if(grid[row][col] != 1) continue;
                if(visited[row][col]) continue;
                // cout << row << endl << col << endl;
                area = max(area, recursion(row,col)+1);
            }
        }
        return area;
    }
};
