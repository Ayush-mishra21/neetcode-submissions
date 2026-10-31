class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = 0;
        for(int A:nums){
            sum += A;
            if(sum <= 0){
                ans = max(ans, sum);
                sum = 0;
            }
        }
        return ans;
    }
};
