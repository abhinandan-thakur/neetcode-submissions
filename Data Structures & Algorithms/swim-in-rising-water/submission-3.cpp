class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        distance[0][0] = grid[0][0];
        pq.push({grid[0][0],0,0});
        vector<pair<int,int>> nei = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        while(!pq.empty()) {
            auto [dist, row, col] = pq.top(); pq.pop();
            if(row == n-1 && col == m-1) return dist;
            if(dist > distance[row][col]) continue;
            for(auto [dr, dc]: nei) {
                int nr = dr+row;
                int nc = dc+col;
                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                int nd = max(grid[nr][nc], dist);
                if(nd >= distance[nr][nc]) continue;
                pq.push({nd, nr, nc});
                distance[nr][nc] = nd;
            }
        }
        return -1;
    }
};
