class Solution {
   public:
    vector<vector<int>> adj;
    vector<int> visited;
    bool ans = false;
    int solve(int node) {
        if(visited[node])ans = true;
        if (adj[node].size() == 0 || visited[node]) return 0;
        visited[node] = 1;
        int temp = 0;
        for (int A : adj[node]) {
            temp += solve(A) + 1;
        }
        return temp;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        int count = solve(0);
        if(ans)return false;
        return count == n - 1;
    }
};
