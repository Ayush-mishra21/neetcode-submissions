class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int ind, vector<int> res) {
        ans.push_back(res);
        if (ind >= nums.size()) {
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i] == nums[i - 1]) {
                continue;
            }
            res.push_back(nums[i]);
            solve(nums, i + 1, res);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        solve(nums, 0, res);
        return ans;
    }
};
