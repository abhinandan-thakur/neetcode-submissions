class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row0 = matrix[0][0];
        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 0) row0 = 0;
        }
        for(int col = 0; col < n; col++) {
            for(int row = 0; row < matrix.size(); row++) {
                if(matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    break;
                }
            }
        }
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    break;
                }
            }
        }

        for(int row = 1; row < m; row++) {
            if(matrix[row][0] == 0) {
                for(int col = 0; col < n; col++) matrix[row][col] = 0;
            }
        }
        for(int col = 0; col < n; col++) {
            if(matrix[0][col] == 0) {
                for(int row = 0; row < m; row++) matrix[row][col] = 0;
            }
        }
        if(row0 == 0) for(int col = 0; col < n; col++) matrix[row0][col] = 0;
    }
};
