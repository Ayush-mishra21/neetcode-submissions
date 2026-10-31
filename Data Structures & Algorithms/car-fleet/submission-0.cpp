class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int>mp;
        for(int i = 0; i < position.size(); i++){
            int time = (target - position[i]) / speed[i];
            mp[time]++;
        }
        return mp.size();
    }
};
