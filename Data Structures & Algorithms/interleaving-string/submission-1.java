class Solution {
    int dp[][][];
    boolean solve(String s1, String s2, String s3, int i1, int i2, int j) {
        if (j >= s3.length()) {
            return i1 >= s1.length() && i2 >= s2.length();
        }
        if (dp[i1][i2][j] != -1) {
            return dp[i1][i2][j] == 1 ? true : false;
        }
        if (i1 < s1.length() && s1.charAt(i1) == s3.charAt(j)) {
            if (i2 < s2.length() && s2.charAt(i2) == s3.charAt(j)) {
                boolean ans =
                    solve(s1, s2, s3, i1 + 1, i2, j + 1) || solve(s1, s2, s3, i1, i2 + 1, j + 1);
                dp[i1][i2][j] = ans ? 1 : 0;
                return ans;
            }
            boolean ans = solve(s1, s2, s3, i1 + 1, i2, j + 1);
            dp[i1][i2][j] = ans ? 1 : 0;
            return ans;
        }
        if (i2 < s2.length() && s2.charAt(i2) == s3.charAt(j)) {
            boolean ans = solve(s1, s2, s3, i1, i2 + 1, j + 1);
            dp[i1][i2][j] = ans ? 1 : 0;
            return ans;
        }
        dp[i1][i2][j] = 0;
        return false;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        dp = new int[s1.length() + 1][s2.length() + 1][s3.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(s1, s2, s3, 0, 0, 0);
    }
}
