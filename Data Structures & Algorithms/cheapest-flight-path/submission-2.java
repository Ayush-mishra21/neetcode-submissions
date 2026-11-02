class Solution {
    List<List<int[]>> adj;
    int[] visited;
    int dp[][][];
    int solve(int src, int dest, int k) {
        if (k < 0) {
            return Integer.MAX_VALUE;
        }

        if (src == dest)
            return 0;
        if(dp[src][dest][k] != -1)return dp[src][dest][k];
        visited[src] = 1;
        int ans = Integer.MAX_VALUE;

        for (int arr[] : adj.get(src)) {
            if (visited[arr[0]] == 1) continue;

            int x = solve(arr[0], dest, k - 1);

            if (x != Integer.MAX_VALUE)
                x += arr[1];

            ans = Math.min(ans, x);
        }

        visited[src] = 0;
        return dp[src][dest][k] = ans;
    }

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        dp = new int[n][n][k+ 2];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                Arrays.fill(dp[i][j], -1);
            }
        }
        adj = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        visited = new int[n];

        for (int i = 0; i < flights.length; i++) {
            int a = flights[i][0];
            int b = flights[i][1];
            int cost = flights[i][2];

            int[] temp = {b, cost};
            adj.get(a).add(temp);
        }

        int ans = solve(src, dst, k + 1);

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}