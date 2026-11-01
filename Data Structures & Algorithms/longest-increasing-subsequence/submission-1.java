class Solution {
    int dp[];
    public int lengthOfLIS(int[] nums) {
        dp = new int[nums.length];
        // for(int i = 0; i < nums.length; i++){
            Arrays.fill(dp, 1);
        // }
        for(int i = 0; i < nums.length; i++){
            for(int j = i; j >= 0; j--){
                if(nums[j] < nums[i]){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    // break;
                }
            }
        }
        int max_ = 0;
        for(int i = 0; i < nums.length; i++){
            max_ = Math.max(max_, dp[i]);
        }
        return max_;
    }
}
