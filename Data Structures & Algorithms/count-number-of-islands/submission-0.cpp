class Solution {
   public:
    void solve(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        int dirr[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int k = 0; k < 4; k++) {
            int newi = i + dirr[k][0], newj = j + dirr[k][1];
            solve(grid, newi, newj);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    solve(grid, i, j);
                }
            }
        }
        return count;
    }
};
