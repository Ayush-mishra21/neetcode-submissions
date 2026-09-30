class Solution {
   public:
    vector<vector<int>> visited;
    bool solve(vector<vector<char>>& board, string word, int i, int j, int ind) {
        if (ind >= word.size()) return true;
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || visited[i][j])
            return false;
        int dirr[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        if (board[i][j] != word[ind]) return false;
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int newi = i + dirr[k][0], newj = j + dirr[k][1];
            if (solve(board, word, newi, newj, ind + 1)) return true;
        }
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        visited.resize(board.size(), vector<int>(board[0].size(), 0));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(word[0] == board[i][j]){
                    if(solve(board, word, i, j, 0))return true;
                }
            }
        }
        return false;
    }
};
