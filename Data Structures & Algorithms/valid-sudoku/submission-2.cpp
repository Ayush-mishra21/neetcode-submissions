class Solution {
public:
    bool isvalid(vector<vector<char>>& board, char dg, int i, int j) {
        int ii = i - 1, jj;

        while (ii >= 0) {
            if (board[ii][j] == dg)
                return false;
            ii--;
        }

        ii = i + 1;

        while (ii < board.size()) {
            if (board[ii][j] == dg)
                return false;
            ii++;
        }

        jj = j + 1;

        while (jj < board[0].size()) {
            if (board[i][jj] == dg)
                return false;
            jj++;
        }

        jj = j - 1;

        while (jj >= 0) {
            if (board[i][jj] == dg)
                return false;
            jj--;
        }

        int row = (i / 3) * 3;
        int col = (j / 3) * 3;

        for (ii = row; ii < row + 3; ii++) {
            for (jj = col; jj < col + 3; jj++) {
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