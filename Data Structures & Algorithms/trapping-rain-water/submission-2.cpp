class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size(), 0), right(height.size(), 0);
        int max_ = 0;
        for(int i = 0; i < height.size(); i++){
            max_ = max(height[i], max_);
        }
    }
};
