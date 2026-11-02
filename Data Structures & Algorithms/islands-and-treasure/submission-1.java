class Solution {
    public void islandsAndTreasure(int[][] grid) {
        Queue<int[]> qu = new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    int temp[] = {i, j, 0};
                    qu.add(temp);
                }
            }
        }
        while (!qu.isEmpty()) {
            int temp[] = qu.poll();
            int i = temp[0], j = temp[1], dist = temp[2];
            // grid[i][j] = dist;
            int [][]dirr = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
            for (int k = 0; k < 4; k++) {
                int newi = i + dirr[k][0], newj = j + dirr[k][1];
                if(newi >= 0 && newj >= 0 && newi < grid.length && newj < grid[0].length && grid[newi][newj] != -1){
                    temp = new int[]{newi, newj, dist + 1};
                    int newdist = dist + 1;
                    if(grid[newi][newj] > newdist){
                        grid[newi][newj] = newdist;
                        qu.add(temp);
                    }
                }
            }
        }
    }
}
