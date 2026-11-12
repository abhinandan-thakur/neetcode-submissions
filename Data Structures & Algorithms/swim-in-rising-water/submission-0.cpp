class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<pair<int,int>> nei = {{1,0},{0,1},{-1,0},{0,-1}};
        pq.push({grid[0][0],0,0});
        distance[0][0] = grid[0][0];
        while(!pq.empty()) {
            auto [cost, row, col] = pq.top(); pq.pop();
            if(distance[row][col] < cost) continue;
            for(auto [dr, dc]: nei) {
            int nr = row+dr;
                int nc = col+dc;
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                int np = max(cost, grid[nr][nc]);
                if(distance[nr][nc] <= np) continue;
                pq.push({np, nr, nc});
                distance[nr][nc] = np;
            }
        }
        return distance[n-1][m-1];
    }
};
