class Solution {
    int []visited;
    List<List<Integer>>adj;
    boolean cycle = false;
    void traverse(int node, int par){
        if(visited[node] == 1){
            cycle = true;
            return;
        }
        visited[node] = 1;
        for(int A : adj.get(node)){
            if(A == par)continue;
            traverse(A, node);
        }
    }
    public boolean validTree(int n, int[][] edges) {
        visited = new int[n];
        adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for(int i = 0; i < edges.length; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        traverse(0, -1);
        if(cycle)return false;
        for(int i = 0; i < n; i++){
            if(visited[i] != 1)return false;
        }
        return true;
    }
}
