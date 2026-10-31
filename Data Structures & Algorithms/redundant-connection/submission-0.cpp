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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
        pair<int, int>res;
        for(int i = 0; i < edges.size(); i++){
            if(parent[edges[i][0]] == parent[edges[i][1]]){
                res = {edges[i][0], edges[i][1]};
            }
            else{
                solve(edges[i][0], edges[i][1]);
            }
        }
        return {res.first, res.second};
    }
};
