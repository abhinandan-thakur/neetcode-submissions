class Solution {
private:
    vector<bool> rowVisited, colVisited, d1Visited, d2Visited;
    vector<string> board;
    vector<vector<string>> ans;
    int n;
    void recursion(int row = 0) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        if(rowVisited[row]) return;
        for(int col = 0; col < n; col++) {
            if(colVisited[col]) continue;
            if(d1Visited[row+col]) continue;
            if(d2Visited[row-col+(n-1)]) continue;

            board[row][col] = 'Q';
            rowVisited[row] = true;
            colVisited[col] = true;
            d1Visited[row+col] = true;
            d2Visited[row-col+(n-1)] = true;

            recursion(row+1);

            board[row][col] = '.';
            rowVisited[row] = false;
            colVisited[col] = false;
            d1Visited[row+col] = false;
            d2Visited[row-col+(n-1)] = false;

        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        rowVisited = colVisited = vector<bool>(n, false);
        d1Visited = d2Visited = vector<bool>(2*n-1, false);
        board = vector<string>(n, string(n, '.'));
        this->n = n;
        recursion();
        return ans;
    }
};
