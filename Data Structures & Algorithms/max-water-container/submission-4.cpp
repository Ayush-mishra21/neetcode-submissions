class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max_ = 0;
        
        // maxl[i] = {max height till i (inclusive), index of that max}
        vector<pair<int, int>> maxl(n), maxr(n);
        
        for(int i = 0; i < n; i++) {
            if (heights[i] > max_) {
                max_ = heights[i];
                maxl[i] = {max_, i};
            } else {
                maxl[i] = (i == 0) ? make_pair(0, 0) : maxl[i - 1];
            }
        }

        max_ = 0;
        for(int i = n - 1; i >= 0; i--) {
            if (heights[i] > max_) {
                max_ = heights[i];
                maxr[i] = {max_, i};
            } else {
                maxr[i] = (i == n - 1) ? make_pair(0, n - 1) : maxr[i + 1];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int min_ = std::min(maxl[i].first, maxr[i].first);
            int diff = abs(maxr[i].second - maxl[i].second);
            ans = std::max(ans, min_ * diff);
        }
        
        return ans;
    }
};