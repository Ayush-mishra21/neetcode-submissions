class Solution {
    int dp[][];
    int solve(int[] prices, int ind, int prevind) {
        if (ind >= prices.length)
            return 0;
        if(dp[ind][prevind+1] != -1){
            return dp[ind][prevind+1];
        }
        if (prevind != -1) {
            int ans = prices[ind] - prices[prevind];
            if (ans > 0) {
                return dp[ind][prevind+1] = Math.max(solve(prices, ind + 1, prevind), solve(prices, ind + 2, -1) + ans);
            } else {
                return dp[ind][prevind+1] = solve(prices, ind + 1, prevind);
            }

        } else {
            return dp[ind][prevind+1] = Math.max(solve(prices, ind + 1, ind), solve(prices, ind + 1, -1));
        }
    }
    public int maxProfit(int[] prices) {
        dp = new int[prices.length][prices.length + 1];
        for(int i = 0; i < prices.length; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(prices, 0, -1);
    }
}
