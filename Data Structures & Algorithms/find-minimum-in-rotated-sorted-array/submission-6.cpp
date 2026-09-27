class Solution {
   public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, ans = -1, n = nums.size();
        if (nums[0] <= nums[n - 1]) return nums[0];
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (mid - 1 >= 0 && nums[mid - 1] < nums[mid] && mid + 1 < nums.size() &&
                nums[mid + 1] < nums[mid]) {
                ans = mid;
                break;
            } else if (nums[i] > nums[mid]) {
                if (ans == -1 || (nums[ans] < nums[j])) {
                    ans = j;
                }
                j = mid - 1;
            } else {
                if (ans == -1 || (nums[ans] < nums[i])) {
                    ans = i;
                }
                i = mid + 1;
            }
        }
        return nums[(ans + 1) % n];
    }
};
