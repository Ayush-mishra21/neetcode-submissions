class Solution {
    int dp[][];
    boolean solve(String s, String p, int i, int j) {
        if (i >= s.length()) {
            if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                j++;
            }
            for (; j < p.length(); j += 2) {
                if (p.charAt(j) != '*') {
                    return false;
                }
                if (j + 1 < p.length() && j + 2 >= p.length() && p.charAt(j + 1) != '*')
                    return false;
            }
            return j >= p.length();
        }
        if (j >= p.length()) {
            return i >= s.length();
        }
        if (dp[i][j] != -1)
            return dp[i][j] == 1;
        boolean flag = false;
        if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
            flag = true;
        }
        if (flag) {
            boolean ans = solve(s, p, i, j + 2);

            if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
                ans = ans || solve(s, p, i + 1, j);
            }
            dp[i][j] = ans ? 1 : 0;
            return ans;
        }
        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
            boolean ans = solve(s, p, i + 1, j + 1);
            dp[i][j] = ans ? 1 : 0;
            return ans;
        }
        dp[i][j] = 0;
        return false;
    }
    public boolean isMatch(String s, String p) {
        dp = new int[s.length()][p.length()];
        for (int i = 0; i < s.length(); i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(s, p, 0, 0);
    }
}
