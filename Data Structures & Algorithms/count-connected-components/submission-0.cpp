class Solution {
   public:
    vector<int> parent, size;
    int par(int m) {
        if (parent[m] == m) return m;
        return parent[m] = par(parent[m]);
    }
    void solve(int u, int v) {
        int ultpu = par(u);
        int ultpv = par(v);
        if (ultpv == ultpu) return;
        if (size[ultpv] > size[ultpu]) {
            parent[ultpu] = ultpv;
        } else if (size[ultpv] < size[ultpu]) {
            parent[ultpv] = ultpu;
        } else {
            parent[ultpv] = ultpu;
            size[ultpu] += size[ultpv];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        parent.resize(n, 0);
        size.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            solve(edges[i][0], edges[i][1]);
        }
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) ans++;
        }
        return ans;
    }
};
