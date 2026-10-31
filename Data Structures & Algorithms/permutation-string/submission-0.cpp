class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp, mp1;
        for(char A : s1)mp[A]++;
        mp1 = mp;
        int j = 0;
        while(j < s2.size()){
            if(mp1.find(s2[j]) == mp1.end()){
                mp1 = mp;
            }
            else{
                mp1[s2[j]]--;
                if(mp1[s2[j]] == 0)mp1.erase(s2[j]);
            }
            if(mp1.size() == 0){
                return true;
            }
            j++;
        }
        return false;
    }
};
