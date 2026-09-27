class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pqmin;
        unordered_map<int, int>mp;
        for(int A : nums)mp[A]++;
        for(auto A : mp){
            pqmin.push({A.second, A.first});
            if(pqmin.size() > k){
                pqmin.pop();
            }
        }
        vector<int>ans;
        while(!pqmin.empty()){
            ans.push_back(pqmin.top().second);
            pqmin.pop();
        }
        return ans;
    }
};
