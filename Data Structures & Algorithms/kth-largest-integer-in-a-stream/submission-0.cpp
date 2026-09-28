class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> pqmax;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int A : nums) {
            pqmax.push(A);
            if (pqmax.size() > K) {
                pqmax.pop();
            }
        }
    }

    int add(int val) {
        pqmax.push(val);
        if (pqmax.size() > K) {
            pqmax.pop();
        }
        return pqmax.top();
    }
};
