class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>>qu;
         vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    qu.push({i, {j, 0}});
                    visited[i][j] = 1;
                }
            }
        }
        while(!qu.empty()){
            int i = qu.front().first;
            int j = qu.front().second.first;
            int cnt = qu.front().second.second;
            qu.pop();
            if(grid[i][j] == 2147483647){
                grid[i][j] = cnt;
            }
            int dirr[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            for(int k = 0; k < 4; k++){
                int newi = i + dirr[k][0], newj = j + dirr[k][1];
                if(newi >= grid.size() || newj >= grid[0].size() || i < 0 || j < 0 || visited[newi][newj] || grid[newi][newj] == -1){
                    continue;
                }
                qu.push({newi, {newj, cnt + 1}});
                visited[newi][newj] = 1;
            }
        }
    }
};
