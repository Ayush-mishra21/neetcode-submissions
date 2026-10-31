class Solution {
public:

    string encode(vector<string>& strs) {
           string ans = "";
           for(string str : strs){
              ans += str;
              ans += "#";
           }
           return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string str = "";
        for(char A : s){
            if(A == '#'){
                ans.push_back(str);
                str = "";
            }
            else{
                str += A;
            }
        }
        return ans;
    }
};
