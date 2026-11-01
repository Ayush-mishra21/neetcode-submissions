class Solution {
    int dp[][];
    int solve(int i, int n, int j, int m){
        if(i == n - 1 && j == m - 1)return 1;
        if(i >= n || j >= m)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = solve(i + 1, n, j, m) + solve(i, n, j + 1, m);
    }
    public int uniquePaths(int m, int n) {
        dp = new int[m][n];
        for(int i = 0; i < m; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(0, m, 0, n);
    }
}
