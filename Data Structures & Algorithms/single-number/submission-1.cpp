class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans = 0;
       for(int A : nums){
          ans ^= A;
       }
       return ans;
    }
};
