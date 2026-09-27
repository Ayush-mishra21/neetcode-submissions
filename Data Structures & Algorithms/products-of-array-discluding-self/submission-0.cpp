class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int zero = 0;
       vector<int>ans(nums.size(), 0);
       int product = 1;
       for(int A : nums){
          if(A == 0){
            zero++;
          }
          else{
            product *= A;
          }
       }
       if(zero > 1){
          return ans;
       }
       else if(zero == 1){
          for(int i = 0; i < nums.size(); i++){
          if(nums[i] == 0){
            ans[i] = product;
            break;
          }
       }
       }
       else{
        for(int i = 0; i < nums.size(); i++){
           ans[i] = product / nums[i];
       }
       }
    return ans;
    }
};
