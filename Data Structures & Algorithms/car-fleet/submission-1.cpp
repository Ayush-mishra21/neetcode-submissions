class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, double> mp;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            mp[position[i]] = time;
        }

        sort(position.rbegin(), position.rend());

        int fleets = 0;
        double maxTime = 0;

        for (int pos : position) {
            double time = mp[pos];

            if (time > maxTime) {
                fleets++;
                maxTime = time;
            }
        }

        return fleets;
    }
};