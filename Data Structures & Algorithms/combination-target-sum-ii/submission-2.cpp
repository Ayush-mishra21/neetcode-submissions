class Solution {
   public:
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    void solve(vector<int>& nums, int ind, int k, vector<int> res) {
        if (k == 0) {
            ans.push_back(res);
            return;
        }
        if (ind >= nums.size()) {
            return;
        }
        // if (mp.find(nums[ind]) != mp.end() && res.size() == 0) {
        //     solve(nums, ind + 1, k, res);
        //     return;
        // }
        // solve(nums, ind + 1, k, res);
        // if (nums[ind] <= k) {
        //     if (res.size() == 0) {
        //         mp[nums[ind]]++;
        //     }
        //     res.push_back(nums[ind]);
        //     solve(nums, ind + 1, k - nums[ind], res);
        // }
        for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i - 1]){
                continue;
            }
            if(nums[i] <= k){
                res.push_back(nums[i]);
                solve(nums, i + 1, k - nums[i], res);
                res.pop_back();
            }
            else{
                break;
            }
        }
       // solve(nums, ind + 1, k, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        solve(candidates, 0, target, res);
        return ans;
    }
};
