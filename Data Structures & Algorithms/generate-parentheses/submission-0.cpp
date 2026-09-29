class Solution {
   public:
    vector<string> ans;
    void solve(int n, int l, int r, string res) {
        if (res.size() == 2*n) {
            if (l == r) 
                ans.push_back(res);
            return;
        }
        solve(n, l + 1, r, res + '(');
        if (l > r) {
            solve(n, l, r + 1, res + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0, "");
        return ans;
    }
};
