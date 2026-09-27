class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int>mp;
        for(int A : nums){
            if(mp.find(A) != mp.end()){
                return true;
            }
            mp[A]++;
        }
        return false;
    }
};