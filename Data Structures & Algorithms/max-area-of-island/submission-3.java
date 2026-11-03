class Solution {
    int dfs(int [][] grid, int i, int j){
        grid[i][j] = -1;
        int dirr[][] = {
            {-1, 0},
            {0, -1},
            {0, 1},
            {1, 0}
        };
        int ans = 0;
        for(int k = 0; k < 4; k++){
            int newi = i + dirr[k][0], newj = j + dirr[k][1];
            if(newi < 0 || newj < 0 || newi >= grid.length || newj >= grid[0].length || grid[newi][newj] == -1 || grid[newi][newj] == 0){
                continue;
            }
            ans += dfs(grid, newi, newj) + 1;
        }
        return ans;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int ans = Integer.MIN_VALUE;
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++){
                if(grid[i][j] == 1){
                    ans = Math.max(ans, dfs(grid, i, j) + 1);
                }
            }
        }
        return ans == Integer.MIN_VALUE?0:ans;
    }
}
