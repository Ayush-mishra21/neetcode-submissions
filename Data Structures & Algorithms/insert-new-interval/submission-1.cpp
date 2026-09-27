class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int i=0;
        while(i<intervals.size()){
            int start=intervals[i][0],end=intervals[i][1];
            bool flag=false;
            while(i<intervals.size() && end>=intervals[i][0]){
                end = max(end, intervals[i][1]);
                i++;
                flag=true;
            }
            ans.push_back({start,end});
            if(!flag)
               i++;
        }
        return ans;
    }
};
