class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int A : nums){
            pq.push(A);
            if(pq.size() > k)pq.pop();
        }
        return pq.top();
    }
};
