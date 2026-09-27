class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxl, maxr;
        int max_ = 0;

        // maxl[i] = max height to the left of i (exclusive)
        for (int i = 0; i < height.size(); i++) {
            maxl.push_back(max_);
            max_ = max(max_, height[i]);
        }

        max_ = 0;
        // same for right, but build it reversed
        for (int i = height.size() - 1; i >= 0; i--) {
            maxr.push_back(max_);
            max_ = max(max_, height[i]);
        }

        // reverse maxr to match the index
        reverse(maxr.begin(), maxr.end());

        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            int water = min(maxl[i], maxr[i]) - height[i];
            if (water > 0) ans += water;
        }

        return ans;
    }
};
