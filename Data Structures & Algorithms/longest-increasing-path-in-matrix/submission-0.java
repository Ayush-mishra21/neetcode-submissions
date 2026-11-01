class Solution {
    int dp[][];
    int solve(int[][] matrix, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];
        int[][] dirr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int newi = i + dirr[k][0], newj = j + dirr[k][1];
            if (newi >= 0 && newj >= 0 && newi < matrix.length && newj < matrix[0].length
                && matrix[i][j] < matrix[newi][newj]) {
                ans = Math.max(ans, solve(matrix, newi, newj) + 1);
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    public int longestIncreasingPath(int[][] matrix) {
        int ans = 0;
        dp = new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                ans = Math.max(ans, solve(matrix, i, j) + 1);
            }
        }
        return ans;
    }
}
