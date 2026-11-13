class Solution {
private:
    vector<string> board;
    vector<vector<string>> results;
    vector<bool> visitedCol;
    vector<bool> diagonal1;
    vector<bool> diagonal2;
    int n;
    void recursion(int row) {
        if(row == n) {
            results.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++) {
            int d1 = row+col;
            int d2 = row-col+n-1;
            if(visitedCol[col]) continue;
            if(diagonal1[d1]) continue;
            if(diagonal2[d2]) continue;
            board[row][col] = 'Q';
            visitedCol[col] = diagonal1[d1] = diagonal2[d2] = true;
            recursion(row+1);
            board[row][col] = '.';
            visitedCol[col] = diagonal1[d1] = diagonal2[d2] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        visitedCol = vector<bool>(n, false);
        diagonal1 = vector<bool>(2*n-1, false);
        diagonal2 = vector<bool>(2*n-1, false);
        this->n = n;
        recursion(0);
        return results;
    }
};
