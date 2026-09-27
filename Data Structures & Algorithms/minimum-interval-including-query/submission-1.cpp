class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end()); // sort by left_i
        vector<int> res;

        for (int q : queries) {
            int left = 0, right = intervals.size() - 1;
            int idx = intervals.size(); // default: no valid interval

            // Binary search to find the first interval with left_i > q
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (intervals[mid][0] > q) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            int ans = -1;
            for (int i = 0; i < idx; ++i) {
                if (intervals[i][1] >= q && q>=intervals[i][0]) {
                    int len = intervals[i][1] - intervals[i][0] + 1;
                    if (ans == -1 || len < ans)
                        ans = len;
                }
            }

            res.push_back(ans);
        }

        return res;
    }
};
