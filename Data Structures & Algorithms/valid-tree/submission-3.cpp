class Solution {
   public:
    vector<vector<int>> adj;
    vector<int> visited;
    bool solve(int node) {
        if (visited[node]) return true;
        visited[node] = 1;
        int res = false;
        for (int A : adj[node]) {
            res = res || solve(A);
        }
        return res;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        if (solve(0)) return false;
        return true;
    }
};
