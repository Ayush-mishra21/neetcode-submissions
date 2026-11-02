class Solution {
    int solve(int[] nums, int i, int j){
        int prev1 = 0, prev2 = 0;
        for(; i <= j; i++){
            int temp = prev2 + nums[i];
            prev2 = prev1;
            prev1 = Math.max(prev1, temp);
        }
        return prev1;
    }
    public int rob(int[] nums) {
        if(nums.length == 1)return nums[0];
        return Math.max(solve(nums, 0, nums.length - 2), solve(nums, 1, nums.length - 1));
    }
}
