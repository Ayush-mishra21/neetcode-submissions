class Solution {
public:
    bool solveA(vector<vector<char>>& board, int i, int j) {

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size())
            return false;

        if (board[i][j] == 'X')
            return true;

        if (board[i][j] == 'V')
            return true;

        board[i][j] = 'V';

        bool ans = true;

        int dirr[4][2] = {
            {-1, 0},
            {0, -1},
            {0, 1},
            {1, 0}
        };

        for (int k = 0; k < 4; k++) {

            int I = i + dirr[k][0];
            int J = j + dirr[k][1];

            if (I < 0 || I >= board.size() ||
                J < 0 || J >= board[0].size()) {
                ans = false;
                continue;
            }

            if (board[I][J] == 'O') {
                ans = solveA(board, I, J) && ans;
            }
        }

        if (ans)
            return true;

        board[i][j] = 'O';
        return false;
    }

    void solve(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == 'O') {

                    bool ans = solveA(board, i, j);

                    if (ans)
                        board[i][j] = 'X';
                }
            }
        }
    }
};