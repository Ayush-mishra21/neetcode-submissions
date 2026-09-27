class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp, mp1;
        for(char A : s1)mp[A]++;
        int i = 0, j = 0, count = 0;
        while(j < s2.size()){
            if(mp.find(s2[j]) != mp.end()){
                while(mp[s2[j]] == 0){
                    mp[s2[i]]++;
                    i++;
                }
                mp[s2[j]]--;
            }
            else{
                while(i < j){
                    mp[s2[i]]++;
                    i++;
                }
                i++;
            }
            if(j - i + 1 == s1.size()){
                return true;
            }
            j++;
        }
        return false;
    }
};
