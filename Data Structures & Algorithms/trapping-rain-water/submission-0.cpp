class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>maxl,maxr;
        int max_=-1;
        for(int i=0; i< height.size(); i++){
            maxl.push_back(max_);
            max_=max(max_, height[i]);
        }
        max_=-1;
        for(int i= height.size()-1; i>=0; i--){
            maxr.push_back(max_);
            max_=max(max_, height[i]);
        }
        int ans=0;
        for(int i= height.size()-1; i>=0; i--){
           if(maxl[i]==-1 || maxr[i]==-1)continue;
           ans+=(min(maxl[i], maxr[i])- height[i]);
        }
        return ans;
    }
};
