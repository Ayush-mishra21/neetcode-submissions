class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int>pqmax;
        priority_queue<int, vector<int>, greater<int>>pqmin;
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        for(int A : nums1){
            if(pqmax.empty())pqmax.push(A);
            else{
                if(pqmax.top() < A){
                    pqmin.push(A);
                }
                else{
                    pqmax.push(A);
                }
            }
            if(abs((int)pqmax.size() - (int)pqmin.size()) > 1){
                if(pqmax.size() > pqmin.size()){
                    pqmin.push(pqmax.top());
                    pqmax.pop();
                }
                else{
                    pqmax.push(pqmin.top());
                    pqmin.pop();
                }
            }
            if (pqmin.size() > pqmax.size()) {
            pqmax.push(pqmin.top());
            pqmin.pop();
        }
        }
        if((pqmax.size() + pqmin.size()) % 2 == 0){
            return (pqmax.top() + pqmin.top()) / 2.0;
        } 
        return pqmax.top() / 1.0;
    }
};
