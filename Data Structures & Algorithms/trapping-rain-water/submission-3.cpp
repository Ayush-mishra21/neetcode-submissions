class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left(height.size(), 0), right(height.size(), 0);
        int max_ = 0;
        for(int i = 0; i < height.size(); i++){
            left[i] = max_;
            max_ = max(height[i], max_);
        }
        max_ = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            right[i] = max_;
            max_ = max(height[i], max_);
        }
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
           int res = min(left[i], right[i]) - height[i];
           if(res < 0)continue;
           ans += res;
        }
        return ans;
    }
};
