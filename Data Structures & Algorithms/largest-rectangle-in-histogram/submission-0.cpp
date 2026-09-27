class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        vector<int>left(heights.size()), right(heights.size());
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = heights.size() - 1; i >= 0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                right[i] = heights.size();
            }
            else{
                right[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            int area = right[i] - left[i] - 1;
            ans = max(ans, area * heights[i]);
        }
        return ans;
    }
};
