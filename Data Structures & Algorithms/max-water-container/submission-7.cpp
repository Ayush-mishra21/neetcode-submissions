class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0, i = 0, j = heights.size() - 1;
        while(i < j){
            int res = min(heights[i], heights[j]) * (j - i);
            ans = max(ans, res);
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
