class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        sort(tasks.begin(), tasks.end());

        unordered_map<char, int> mp;

        int i = 0;
        int j = tasks.size() - 1;
        int count = 1;
        int ans = 0;

        while (i <= j) {

            char task;

            // Pick alternately from both ends
            if (i == j) {
                task = tasks[i];
                i++;
            }
            else if (count % 2 == 0) {
                task = tasks[i];
                i++;
            }
            else {
                task = tasks[j];
                j--;
            }

            // If this task was executed before
            if (mp.find(task) != mp.end()) {
                int gap = count - mp[task] - 1;

                if (gap < n) {
                    ans += n - gap;
                    count += n - gap;
                }
            }

            // Execute current task
            mp[task] = count;

            ans++;
            count++;
        }

        return ans;
    }
};