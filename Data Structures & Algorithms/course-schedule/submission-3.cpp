class Solution {
   public:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> done;
    bool solve(int course) {
        if (visited[course]) return false;
        if (done[course]) return true;
        visited[course] = 1;
        for (int A : adj[course]) {
            if (!solve(A)) return false;
        }
        visited[course] = 0;
        done[course] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        done.resize(numCourses, 0);
        visited.resize(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!solve(i)) return false;
        }
        return true;
        ;
    }
};
