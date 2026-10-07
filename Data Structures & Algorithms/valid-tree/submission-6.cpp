class Solution {
   public:
    vector<vector<int>> adj;
    vector<int> visited;

    bool solve(int node, int parent) {
        if (visited[node]) return true;

        visited[node] = 1;
        int res = false;

        for (int A : adj[node]) {
            if (A == parent) continue;

            res = res || solve(A, node);
        }

        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if (solve(0, -1)) return false;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }

        return true;
    }
};