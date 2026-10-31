class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>arr;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            arr.push_back({position[i], time});
        }

        sort(arr.rbegin(), arr.rend());

        stack<int>st;

        for (int ar : arr) {
            double time = ar.second;
            if(st.empty() || time > st.top()){
                st.push(ar.first);
            }
        }

        return st.size();
    }
};