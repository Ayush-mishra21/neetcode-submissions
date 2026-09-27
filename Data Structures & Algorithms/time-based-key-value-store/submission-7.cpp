class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mp[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
       const auto& arr = mp[key]; // O(1) reference - zero copying
        int i = 0, j = arr.size() - 1, ans = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid].first == timestamp) {
                return arr[mid].second;
            } else if (arr[mid].first > timestamp) {
                j = mid - 1;
            } else {
               ans = mid;
                i = mid + 1;
            }
        }
        if (ans == -1) return "";
        return arr[ans].second;
    }
};
