class Solution {
public:

    string encode(vector<string>& strs) {
        vector<string> res;

        for (string str : strs) {
            for (char A : str) {
                res.push_back(to_string(int(A)));
                res.push_back("-");
            }
            res.push_back("@");
        }

        string ans = "";

        for (string str : res) {
            ans += str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str = "";
        int num = 0;

        for (char A : s) {

            if (A == '-') {
                str += char(num);
                num = 0;              
            }
            else if (A == '@') {
                ans.push_back(str);
                str = "";
            }
            else {
                num = num * 10 + (A - '0');
            }
        }

        return ans;
    }
};