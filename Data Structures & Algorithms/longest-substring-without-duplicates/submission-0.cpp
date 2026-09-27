class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        unordered_map<int, int>mp;
        while(j < s.size()){
            while(mp.find(s[j]) != mp.end()){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            mp[s[j]]++;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
