class Solution {
public:
    int solve(string s, string t, int ind, int tind, vector<vector<int>>& dp) {
        if (tind == t.size()) {
            return 1;
        }
        if (ind == s.size()) {
            return 0;
        }
        if (dp[ind][tind] != -1) {
            return dp[ind][tind];
        }
        if (s[ind] == t[tind]) {
            return dp[ind][tind] = solve(s, t, ind + 1, tind + 1, dp) +
                                   solve(s, t, ind + 1, tind, dp);
        } else {
            return dp[ind][tind] = solve(s, t, ind + 1, tind, dp);
        }
    }
    int numDistinct(string s, string t) {
         vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return solve(s, t, 0, 0, dp);
    }
};
