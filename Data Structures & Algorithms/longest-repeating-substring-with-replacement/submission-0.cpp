class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int i = 0, j = 0, ans = 0;
        while(j < s.size()){
            while(mp.size() > 1){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            mp[s[j]]++;
            int res = 0;
            if(j - i + 1 + k <= s.size())
                res += k;
            ans = max(ans, j - i + 1 + res);
            j++;
        }
        return ans;
    }
};
