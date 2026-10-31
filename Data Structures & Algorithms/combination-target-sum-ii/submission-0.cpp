class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int ind, int k, vector<int> res) {
        if (k == 0) {
            ans.push_back(res);
            return;
        }
        if (ind >= nums.size()) {
            return;
        }
        if (ind > 0 && nums[ind] == nums[ind - 1] && res.size() == 0) {
            solve(nums, ind + 1, k, res);
            return;
        }
        solve(nums, ind + 1, k, res);
        if (nums[ind] <= k) {
            res.push_back(nums[ind]);
            solve(nums, ind + 1, k - nums[ind], res);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        solve(candidates, 0, target, res);
        return ans;
    }
};
