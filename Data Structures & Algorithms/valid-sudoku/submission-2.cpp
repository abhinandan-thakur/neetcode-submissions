class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowHash[9] = {};
        int colHash[9] = {};
        int gridHash[9] = {};
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;
                int val = board[row][col] - '1';
                if(rowHash[row] & (1<<val)) return false;
                if(colHash[col] & (1<<val)) return false;
                if(gridHash[(row/3)*3+col/3] & (1<<val)) return false;
                rowHash[row] |= (1<<val);
                colHash[col] |= (1<<val);
                gridHash[(row/3)*3+col/3] |= (1<<val);
            }
        }
        return true;
    }
};
