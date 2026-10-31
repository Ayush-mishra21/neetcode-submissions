class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double> pq;
        for (int i = 0; i < points.size(); i++) {
            int a = points[i][0], b = points[i][1];
            double dist = sqrt(pow(a, 2) + pow(b, 2));
            pq.push(dist);
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
            int a = points[i][0], b = points[i][1];
            double dist = sqrt(pow(a, 2) + pow(b, 2));
            if (dist == pq.top()) {
                ans.push_back({a, b});
            }
        }
        return ans;
    }
};
