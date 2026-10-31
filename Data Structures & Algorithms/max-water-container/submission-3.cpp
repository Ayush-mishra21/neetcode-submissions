class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_=0;
        vector<pair<int,int>>maxl(heights.size()),maxr(heights.size());
        for(int i=0; i<heights.size(); i++){
            maxl[i].push_back({max_,i});
            max_=max(max_,heights[i]);
        }
        max_=0;
         for(int i=heights.size()-1; i>=0; i--){
           maxr[i].push_back({max_,i});
            max_=max(max_,heights[i]);
        }
        int ans=0;
        for(int i=0; i<heights.size(); i++){
            int min_=min(maxl[i].first,maxr[i].first);
            int diff=maxr[i].second - maxl[i].second;
            ans=max(ans,min_*diff);
        }
        return ans;
    }
};
