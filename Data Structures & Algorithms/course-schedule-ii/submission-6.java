class Solution {
    List<List<Integer>> adj;
    int[] visited;
    List<Integer> ans = new ArrayList<>();
    boolean cycle = false;

    void solve(int node) {
        if (visited[node] == 1) {
            cycle = true;
            return;
        }

        if (visited[node] == 2) return;

        visited[node] = 1;

        for (int A : adj.get(node)) {
            solve(A);

            if (cycle) return;
        }

        visited[node] = 2;
        ans.add(node);
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        visited = new int[numCourses];
        adj = new ArrayList<>();
        ans = new ArrayList<>();

        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] p : prerequisites) {
            int a = p[0], b = p[1];
            adj.get(a).add(b);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                solve(i);
                if (cycle) return new int[0];
            }
        }

        int[] result = new int[ans.size()];

        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }

        return result;
    }
}