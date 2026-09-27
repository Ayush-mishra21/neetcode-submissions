class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>qu;
        vector<int>ans;
        int i = 0, j = 0;
        while(j < nums.size()){
            while(!qu.empty() && qu.back() < nums[j]){
                qu.pop_back();
            }
            qu.push_back(nums[j]);
            if(j - i + 1 == k){
                ans.push_back(qu.front());
                if(qu.front() == nums[i]){
                    qu.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
