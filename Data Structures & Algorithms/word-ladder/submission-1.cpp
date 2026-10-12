class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mp(wordList.begin(), wordList.end());

        if (mp.find(endWord) == mp.end())
            return 0;

        queue<pair<int, string>> q;
        unordered_set<string> visited;

        q.push({1, beginWord});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int steps = top.first;
            string word = top.second;

            if (word == endWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                string s = word;

                for (char A = 'a'; A <= 'z'; A++) {
                    if (s[i] == A)
                        continue;

                    s[i] = A;

                    if (mp.find(s) != mp.end() &&
                        visited.find(s) == visited.end()) {
                        visited.insert(s);
                        q.push({steps + 1, s});
                    }
                }
            }
        }

        return 0;
    }
};