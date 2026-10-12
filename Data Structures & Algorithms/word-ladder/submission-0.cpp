class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp, visited;
        for (string str : wordList) mp[str]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        if (mp.find(endWord) == mp.end()) return 0;
        pq.push({1, beginWord});
        visited[beginWord]++;
        while (!pq.empty()) {
            pair<int, string> top = pq.top();
            pq.pop();
            if (top.second == endWord) return top.first;
            for (int i = 0; i < top.second.size(); i++) {
                string s = top.second;
                for (char A = 'a'; A <= 'z'; A++) {
                    s[i] = A;
                    if (mp.find(s) != mp.end() && visited.find(s) == visited.end()) {
                        pq.push({top.first + 1, s});
                        visited[s]++;
                    }
                }
            }
        }
        return 0;
    }
};
