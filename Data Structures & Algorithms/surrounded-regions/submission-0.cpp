class Solution {
private:
    bool metEdge = false;
    vector<vector<bool>> visited;
    vector<vector<char>> board;
    void dfs(int row, int col) {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return;
        if(board[row][col] != 'O') return;
        if(visited[row][col]) return;
        if(row == 0 || row+1 == board.size() || col == 0 || col+1 == board[0].size()) metEdge = true;
        visited[row][col] = true;
        dfs(row+1, col);
        dfs(row-1, col);
        dfs(row, col+1);
        dfs(row, col-1);
        if(!metEdge) board[row][col] = 'X';
    }
public:
    void solve(vector<vector<char>>& board) {
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        this->board = board;
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(board[row][col] == 'X') continue;
                if(visited[row][col]) continue;
                metEdge = false;
                dfs(row, col);
            }
        }
        board = this->board;
    }
};
