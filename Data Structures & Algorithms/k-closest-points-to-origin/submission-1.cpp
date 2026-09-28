class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int a = points[i][0], b = points[i][1];
            double dist = sqrt(pow(a, 2) + pow(b, 2));
            pq.push({dist, i});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
