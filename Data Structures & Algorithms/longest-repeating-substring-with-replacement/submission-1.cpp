class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int i = 0, j = 0, ans = 0, max_freq = 0;
        while(j < s.size()){
            mp[s[j]]++;
            max_freq = max(max_freq, mp[s[j]]);
            while((j - i + 1) - max_freq > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
