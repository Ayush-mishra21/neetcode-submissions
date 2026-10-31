class Solution {
public:

    vector<pair<int,int>> empty;

    bool isvalid(vector<vector<char>>& board, char dg, int i, int j) {

        // column
        int ii = 0;
        while (ii < 9) {
            if (board[ii][j] == dg)
                return false;
            ii++;
        }

        // row
        int jj = 0;
        while (jj < 9) {
            if (board[i][jj] == dg)
                return false;
            jj++;
        }

        // 3 x 3 box
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

    bool solve(vector<vector<char>>& board, int ind) {

        // All empty cells filled
        if (ind == empty.size())
            return true;

        int i = empty[ind].first;
        int j = empty[ind].second;

        for (char k = '1'; k <= '9'; k++) {

            if (isvalid(board, k, i, j)) {

                board[i][j] = k;

                if (solve(board, ind + 1))
                    return true;

                // Backtracking
                board[i][j] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        // Store empty cells only once
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    empty.push_back({i, j});
                }
            }
        }

        solve(board, 0);
    }
};