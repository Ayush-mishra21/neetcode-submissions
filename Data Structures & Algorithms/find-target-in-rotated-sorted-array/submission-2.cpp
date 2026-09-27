class Solution {
   public:
    int solve(vector<int>& nums, int i, int j, int target) {
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, ans = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (mid > 0 && nums[mid] > nums[mid - 1] && mid + 1 < nums.size() &&
                nums[mid] > nums[mid + 1]) {
                ans = mid;
                break;
            } else if (nums[i] > nums[mid]) {
                if (ans == -1 || nums[ans] < nums[j]) {
                    ans = mid;
                }
                j = mid - 1;
            } else {
                if (ans == -1 || nums[ans] < nums[i]) {
                    ans = i;
                }
                i = mid + 1;
            }
        }
        // return nums[ans];
        int res = solve(nums, 0, ans, target);
        if (res != -1) return res;
        return solve(nums, ans + 1, nums.size() - 1, target);
    }
};
