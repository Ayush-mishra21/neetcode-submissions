class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_ = prices[0];
        for(int i = 1; i < prices.size(); i++){
            int res = prices[i] - min_;
            min_ = min(min_, prices[i]);
            if(res < 0)continue;
            ans = max(ans, res);
        }
        return ans;
    }
};
