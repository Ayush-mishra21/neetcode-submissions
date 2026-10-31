class Solution {
public:

    bool isvalid(vector<vector<char>>& board, char dg, int i, int j) {

        // Check row
        for (int jj = 0; jj < 9; jj++) {
            if (board[i][jj] == dg)
                return false;
        }

        // Check column
        for (int ii = 0; ii < 9; ii++) {
            if (board[ii][j] == dg)
                return false;
        }

        // Check 3 x 3 box
        int row = (i / 3) * 3;
        int col = (j / 3) * 3;

        for (int ii = row; ii < row + 3; ii++) {
            for (int jj = col; jj < col + 3; jj++) {
                if (board[ii][jj] == dg)
                    return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    for (char k = '1'; k <= '9'; k++) {

                        if (isvalid(board, k, i, j)) {

                            board[i][j] = k;

                            if (isValidSudoku(board))
                                return true;

                            // Backtracking
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
};