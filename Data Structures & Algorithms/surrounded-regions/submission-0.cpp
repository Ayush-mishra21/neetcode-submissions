class Solution {
   public:
    bool solveA(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'X') return true;
        board[i][j] = 'X';
        int dirr[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        bool ans = true;
        for (int k = 0; k < 4; k++) {
            int I = i + dirr[k][0], J = j + dirr[k][1];
            if (I < 0 || I >= board.size() || J < 0 || J >= board[0].size()) {
                return false;
            }
            ans = ans && solveA(board, I, J);
        }
        if (ans) {
            return true;
        } else {
            board[i][j] = 'O';
        }
        return false;
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    int dirr[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
                    bool ans = true;
                    for (int k = 0; k < 4; k++) {
                        int I = i + dirr[k][0], J = j + dirr[k][1];
                        if (I < 0 || I >= board.size() || J < 0 || J >= board[0].size()) {
                            ans = false;
                            break;
                        }
                        ans = ans && solveA(board, I, J);
                    }
                    if (ans)  board[i][j] = 'X';
                }
            }
        }
    }
};
