class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int> res, vector<int>&visited) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                res.push_back(nums[i]);
                visited[i] = 1;
                solve(nums, res, visited);
                res.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res, visited(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(nums[i]);
            visited[i] = 1;
            solve(nums, res, visited);
            res.pop_back();
            visited[i] = 0;
        }

        return ans;
    }
};
