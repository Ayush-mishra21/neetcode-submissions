class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0,j=nums.size()-1;
        unordered_map<int,int>mp;
        int k=0;
        for(int a:nums)mp[a]=k++;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(mp.find(-(nums[i]+nums[j]))!=mp.end() && i!=j && j!=mp[-(nums[i]+nums[j])] && i!=mp[-(nums[i]+nums[j])]){
                    ans.push_back({mp[-(nums[i]+nums[j])],nums[i],nums[j]});
                }
            } 
        }
        return ans;
    }
};
