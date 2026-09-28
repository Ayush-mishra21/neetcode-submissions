class MedianFinder {
   public:
    MedianFinder() {}
    priority_queue<int> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    void addNum(int num) {
        if (pqmax.empty()) {
            pqmax.push(num);
        } else {
            if (pqmax.top() <= num) {
                pqmin.push(num);
            } else {
                pqmax.push(num);
            }
        }
        if (abs(int(pqmax.size()) - int(pqmin.size())) > 1) {
            if (pqmax.size() > pqmin.size()) {
                pqmin.push(pqmax.top());
                pqmax.pop();
            } else {
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
        }
    }

    double findMedian() {
        if ((pqmax.size() + pqmin.size()) % 2 == 0) {
            return (pqmax.top() + pqmin.top()) / 2.0;
        }
        if (pqmax.size() > pqmin.size()) {
            return pqmax.top() / 1.0;
        }
        return pqmin.top() / 1.0;
    }
};
