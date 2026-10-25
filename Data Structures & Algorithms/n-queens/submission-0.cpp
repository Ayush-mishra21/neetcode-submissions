class Solution {
   public:
    vector<vector<string>> ans;

    bool valid(vector<string>& res, int i, int j) {
        int n = res.size();

        for (int x = 0; x < n; x++) {
            if (res[i][x] == 'Q') return false;
            if (res[x][j] == 'Q') return false;
        }

        int x = i - 1, y = j - 1;
        while (x >= 0 && y >= 0) {
            if (res[x][y] == 'Q') return false;
            x--, y--;
        }

        x = i - 1, y = j + 1;
        while (x >= 0 && y < n) {
            if (res[x][y] == 'Q') return false;
            x--, y++;
        }

        x = i + 1, y = j - 1;
        while (x < n && y >= 0) {
            if (res[x][y] == 'Q') return false;
            x++, y--;
        }

        x = i + 1, y = j + 1;
        while (x < n && y < n) {
            if (res[x][y] == 'Q') return false;
            x++, y++;
        }

        return true;
    }

    void solve(vector<string>& res, int row, int n) {
    if (row == n) {
        ans.push_back(res);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (res[row][j] == '.' && valid(res, row, j)) {
            res[row][j] = 'Q';

            solve(res, row + 1, n);

            res[row][j] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> res(n, string(n, '.'));
        solve(res,0, n);
        return ans;
    }
};
