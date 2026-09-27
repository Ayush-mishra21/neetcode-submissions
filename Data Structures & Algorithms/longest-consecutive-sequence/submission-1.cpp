class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, int> mp;
        int ans = 0;

        for (int A : nums) {

            if (mp.find(A) != mp.end())
                continue;

            int left = 0;
            int right = 0;

            if (mp.find(A - 1) != mp.end())
                left = mp[A - 1];

            if (mp.find(A + 1) != mp.end())
                right = mp[A + 1];

            int len = left + 1 + right;

            mp[A] = len;

            // Update left boundary
            if (left > 0)
                mp[A - left] = len;

            // Update right boundary
            if (right > 0)
                mp[A + right] = len;

            ans = max(ans, len);
        }

        return ans;
    }
};