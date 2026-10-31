class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int i = 1;
       sort(nums.begin(), nums.end());
       for(int A : nums){
          if(A != i){
             return A;
          }
          i++;
       } 
       return -1;
    }
};
