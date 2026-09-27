class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(char A : t)mp[A]++;
        int i = 0, j = 0, count = 0;
        string ans = "", res;
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count++;
                }
            }
            if(count == mp.size()){
                while(count == mp.size()){
                    if(mp.find(s[i]) != mp.end()){
                        if(mp[s[i]] == 0){
                            count--;
                        }
                        mp[s[i]]++;
                    }
                    i++;
                }
                res = s.substr(i - 1, j - i + 2);
                if(ans.size() > res.size() || ans.empty())
                    ans = res;
            }
            j++;
        }
        return ans;
    }
};
