class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        vector<pair<int, int>> res;
        for (int A : arr) {
            int diff = abs(A - x);
            res.push_back({diff, A});
        }
        sort(res.begin(), res.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        for (int i = 0; i < res.size() && k--; i++) {
            ans.push_back(res[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};