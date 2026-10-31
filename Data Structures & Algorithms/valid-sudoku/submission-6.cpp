class Solution {
public:

     bool possible(vector<vector<char>>& board, char k, int row, int col) {
        int newrow = (row / 3) * 3;
        int newcol = (col / 3) * 3;

        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == k || board[row][i] == k)
                return false;
        }
        for (int i = newrow; i < newrow + 3; i++) {
            for (int j = newcol; j < newcol + 3; j++) {
                if (board[i][j] == k) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (possible(board, k, i, j)) {
                            board[i][j] = k;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};