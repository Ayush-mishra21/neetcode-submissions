class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        for(string str : strs){
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }
        for(auto A : mp){
            ans.push_back(A.second);
        }
        return ans;
    }
};
