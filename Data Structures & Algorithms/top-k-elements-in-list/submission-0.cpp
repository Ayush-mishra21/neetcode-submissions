class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pqmin;
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        for(int A : nums){
            pqmin.push(A);
            if(pqmin.size() > k){
                pqmin.pop();
            }
        }
        vector<int>ans;
        while(!pqmin.empty()){
            ans.push_back(pqmin.top());
            pqmin.pop();
        }
        return ans;
    }
};
