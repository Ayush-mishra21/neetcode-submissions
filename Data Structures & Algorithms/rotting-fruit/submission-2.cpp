class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int, int>> qu;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    ans++;
                } else if (grid[i][j] == 2) {
                    qu.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }
        int res = -1;
        while (!qu.empty()) {
            int dirr[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            int size = qu.size();
            while (size) {
                int I = qu.front().first, J = qu.front().second;
                qu.pop();
                for (int k = 0; k < 4; k++) {
                    int i = I + dirr[k][0];
                    int j = J + dirr[k][1];
                    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
                        grid[i][j] == 0)
                        continue;
                    ans--;
                    grid[i][j] = 0;
                    qu.push({i, j});
                }
                size--;
            }
            res++;
        }
        if(ans == 0 && res == -1)return 0;
        if (ans > 0) return -1;
        return res;
    }
};
