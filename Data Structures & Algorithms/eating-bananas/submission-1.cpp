class Solution {
public:
    bool solve(int k, vector<int>& piles, int &h){
        int m = 0;
        for(int A : piles){
            if(A <= k){
                m++;
            }
            else{
                m += ((A + k - 1) / k);
            }
        }
        return m <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1, i = 1, j = *max_element(piles.begin(), piles.end());
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(solve(mid, piles, h)){
                j = mid - 1;
                ans = mid;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};
