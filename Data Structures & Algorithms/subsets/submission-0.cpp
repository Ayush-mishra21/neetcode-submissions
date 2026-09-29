class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int ind, vector<int>res){
        if(ind >= nums.size()){
            ans.push_back(res);
            return;
        }
        solve(nums, ind + 1, res);
        res.push_back(nums[ind]);
        solve(nums, ind + 1, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        solve(nums, 0, res);
        return ans;
    }
};
