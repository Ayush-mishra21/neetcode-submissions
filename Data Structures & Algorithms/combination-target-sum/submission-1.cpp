class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int ind, vector<int> res, int k) {
        if (k == 0) {
            ans.push_back(res);
            return;
        }
        if (ind >= nums.size()) {
            return;
        }
        solve(nums, ind + 1, res, k);
        if (nums[ind] <= k) {
            res.push_back(nums[ind]);
            solve(nums, ind, res, k - nums[ind]);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> res;
        solve(nums, 0, res, target);
        return ans;
    }
};
