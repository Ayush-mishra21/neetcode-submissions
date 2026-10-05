class Solution {
public:
    vector<vector<int>> visited;
    void solveA(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            visited[i][j] == 1 || board[i][j] == 'X')
            return;
        visited[i][j] = 1;
        int dirr[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int k = 0; k < 4; k++) {
            int newi = i + dirr[k][0], newj = j + dirr[k][1];
            solveA(board, newi, newj);
        }
    }
    void solve(vector<vector<char>>& board) {
        visited.resize(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' && (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1))
                    solveA(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (visited[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};