class Solution {
private:
    std::vector <std::pair <int,int>> nei = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    bool exist(vector<vector<char>>& board, string target) {
        queue<
            tuple<
                int,
                int,
                string,
                set<pair<int,int>>
                >
            > q;
        // row,col only two states we require as of now...
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(board[row][col] == target[0]) {
                    string s1 = string(1,target[0]);
                    set<pair<int,int>> s2;
                    s2.insert({row,col});
                    q.push({row, col, s1, s2});
                }
            }
        }
        int level = 1;
        while(!q.empty()) {
            int levelSize = q.size();
            while(levelSize--) {
                auto &t = q.front();
                int row = get<0>(t);
                int col = get<1>(t);
                string word = get<2>(t);
                set<pair<int,int>> visited = get<3>(t);
                if(word == target) return true;
                for(auto [dr,dc]: nei) {
                    int nr = row+dr;
                    int nc = col+dc;
                    if(nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size()) continue;
                    // need to track visited too somehow...
                    if(visited.count({nr,nc})) continue;
                    if(board[nr][nc] != target[level]) continue;
                    string nextWord = word+board[nr][nc];
                    auto nextVisited = visited;
                    nextVisited.insert({nr,nc});
                    q.push({nr, nc, nextWord, nextVisited});
                }
                q.pop();
            }
            level++;
            if(level > target.size()+1) return false;
        }
        return false;
    }
};
