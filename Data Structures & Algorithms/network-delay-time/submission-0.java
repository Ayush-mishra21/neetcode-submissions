class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<ArrayList<Integer>>> adj = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < times.length; i++) {
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            adj.get(a).add(new ArrayList<>(Arrays.asList(b, c)));
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>( (a, b) -> Integer.compare(a[0], b[0]));
        int dist[] = new int[n + 1];
        for(int i = 0; i <= n; i++){
            dist[i] = Integer.MAX_VALUE;
        }
        dist[k] = 0;
        pq.add(new int[] {0, k});
        while (!pq.isEmpty()) {
            int[] temp = pq.poll();
            for (ArrayList<Integer>arr : adj.get(temp[1])) {
                if (dist[arr.get(0)] > arr.get(1) + temp[0]) {
                    dist[arr.get(0)] = arr.get(1) + temp[0];
                    pq.add(new int[]{arr.get(1) + temp[0], arr.get(0)});
                }
            }
        }
       int ans = 0;

for(int i = 1; i <= n; i++){
    ans = Math.max(ans, dist[i]);
}
        return ans == Integer.MAX_VALUE?-1:ans;
    }
}
