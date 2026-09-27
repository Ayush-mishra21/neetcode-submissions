#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;

    TimeMap() {}

    void set(std::string key, std::string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    std::string get(std::string key, int timestamp) {
        // Prevent key creation and return empty string if key doesn't exist
        auto it = mp.find(key);
        if (it == mp.end()) return "";

        // Use const reference to avoid copying the vector
        const auto& arr = it->second;

        int i = 0, j = arr.size() - 1, ans = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid].first == timestamp) {
                return arr[mid].second;
            } else if (arr[mid].first > timestamp) {
                j = mid - 1;
            } else {
                ans = mid; // Correctly updates to the most recent valid timestamp <= target
                i = mid + 1;
            }
        }

        if (ans == -1) return "";
        return arr[ans].second;
    }
};