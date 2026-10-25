class Solution {
   public:
    vector<vector<string>> ans;
    void solve(string s, int ind, vector<string> res) {
        if (ind >= s.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = 1; i + ind <= s.size(); i++) {
            string substr = s.substr(ind, i);
            if (substr.size() != 0 && valid(substr)) {
                res.push_back(substr);
                solve(s, ind + i, res);
                res.pop_back();
            }
        }
    }
    bool valid(string res) {
        for (int i = 0; i < res.size() / 2; i++) {
            if (res[i] != res[res.size() - 1 - i]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> res;
        solve(s, 0, res);
        return ans;
    }
};
