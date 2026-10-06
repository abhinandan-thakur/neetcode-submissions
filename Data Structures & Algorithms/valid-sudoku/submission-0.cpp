class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        string rowArr[9];
        string colArr[9];
        string gridArr[9];

        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;
                rowArr[row] += board[row][col];
                colArr[col] += board[row][col];
                int rowGrid = row/3;
                int colGrid = col/3;
                gridArr[3*rowGrid+colGrid] += board[row][col];
            }
        }
        // 1. columns check
        for(int i = 0; i < 9; i++) {
            unordered_set<char> c;
            cout << "i: " << i << endl;
            cout << "col:" << endl;
            for(auto ch : colArr[i]) {
                cout << ch << ',';
                if(c.count(ch)) return false;
                c.insert(ch);
            }
            unordered_set<char> r;
            cout << endl << "row:" << endl;
            for(auto ch : rowArr[i]) {
                cout << ch << ',';
                if(r.count(ch)) return false;
                r.insert(ch);
            }
            unordered_set<char> g;
            cout << endl << "grid:" << endl;
            for(auto ch: gridArr[i]) {
                cout << ch << ',';
                if(g.count(ch)) return false;
                g.insert(ch);
            }
        }
        // 2. row check
        
        // 3. grid check
        return true;
    }
};

/*
Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit 1-9 or '.'.
    a row check checking for any iteration than comparing with each row element
    n3
    same with column
    a better way is just storing each row in a nah thats bad we can use a better way i guess
    take two vectors for row and columsn store all the string with values in the number
    use an unordered map for detcting any false value
    take a third grid value 
    00 ,01, 02, 03, 04, 05, 06, 07, 08
    10, 11, 12, 13, 14, 15, 16, 17, 18
    20, 21, 22, 23, 24, 25, 26, 27, 28

    there is a trick for this but latter not right now

constraints are relaxed i can do brute force
*/
