class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int>qu;
        vector<int>ans;
        int i = 0, j = 0;
        while(j < nums.size()){
            while(!qu.empty() && qu.front() < nums[j]){
                qu.pop();
            }
            qu.push(nums[j]);
            if(j - i + 1 == k){
                ans.push_back(qu.front());
                // if(qu.front() == nums[i]){
                //     qu.pop();
                // }
                i++;
            }
            j++;
        }
        return ans;
    }
};
