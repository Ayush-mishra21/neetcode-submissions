class Twitter {
public:
    map<int, vector<int>> flowing;
    map<int, vector<pair<int, int>>> post;
    int time;

    Twitter() {
        time = 1;
    }

    void postTweet(int userId, int tweetId) {
        post[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pqmax;

        vector<int> folow = flowing[userId];

        vector<pair<int, int>> res;

        // Followed users' tweets
        for (int id : folow) {
            res.insert(
                res.end(),
                post[id].begin(),
                post[id].end()
            );
        }

        // Own tweets
        res.insert(
            res.end(),
            post[userId].begin(),
            post[userId].end()
        );

        // Keep latest 10 tweets
        for (pair<int, int> A : res) {
            pqmax.push(A);

            if (pqmax.size() > 10) {
                pqmax.pop();
            }
        }

        // Heap gives oldest -> newest
        while (!pqmax.empty()) {
            ans.push_back(pqmax.top().second);
            pqmax.pop();
        }

        // Required: newest -> oldest
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void follow(int followerId, int followeeId) {
        flowing[followerId].push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto it = find(
            flowing[followerId].begin(),
            flowing[followerId].end(),
            followeeId
        );

        if (it != flowing[followerId].end()) {
            flowing[followerId].erase(it);
        }
    }
};