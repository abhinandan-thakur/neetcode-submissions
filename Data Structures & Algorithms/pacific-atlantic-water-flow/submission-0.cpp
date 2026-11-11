class Solution {
private:
    vector<pair<int,int>> nei = {{1,0}, {0,1}, {0,-1}, {-1,0}};
    vector<vector<int>> heights;
    void bfs(queue<pair<int,int>> q, vector<vector<bool>> &visited) {
         while(!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            visited[row][col] = true;
            for(auto [dr,dc]: nei) {
                int nr = row+dr;
                int nc = col+dc;
                if(nr < 0 || nc < 0 || nr >= visited.size() || nc >= visited[0].size()) continue;
                if(visited[nr][nc]) continue;
                if(heights[nr][nc] < heights[row][col]) continue;
                q.push({nr, nc});
            }
         }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int m = heights.size();
       int n = heights[0].size();
       this->heights = heights;
       vector<vector<bool>> pacificGrid(m, vector<bool>(n, false));
       vector<vector<bool>> atlanticGrid(m, vector<bool>(n, false));
       queue<pair<int,int>> pacificQ, atlanticQ;
       for(int row = 0; row < m; row++) {
            pacificQ.push({row, 0});
            atlanticQ.push({row, n-1});
       }
       for(int col = 0; col < n; col++) {
            pacificQ.push({0, col});
            atlanticQ.push({m-1, col});
       }
       bfs(pacificQ, pacificGrid);
       bfs(atlanticQ, atlanticGrid);
       
       vector<vector<int>> res;
       
       for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacificGrid[i][j] && atlanticGrid[i][j]) res.push_back({i,j});
            }
       }
       return res;
    }
};
