class Solution {
    public int orangesRotting(int[][] grid) {
        int count = 0;
        Queue<int[]> qu = new LinkedList<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1)
                    count++;
                if (grid[i][j] == 2) {
                    int[] temp = {i, j, 0};
                    qu.add(temp);
                }
            }
        }
        if(count == 0)return 0;
        while (!qu.isEmpty()) {
            int[] temp = qu.poll();
            int[][] dirr = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
            for (int k = 0; k < 4; k++) {
                int newi = temp[0] + dirr[k][0], newj = temp[1] + dirr[k][1];
                if (newi >= 0 && newj >= 0 && newi < grid.length && newj < grid[0].length
                    && grid[newi][newj] == 1) {
                    count--;
                    grid[newi][newj] = 2;
                    if (count == 0) {
                        return temp[2] + 1;
                    }
                    int[] temp1 = {newi, newj, temp[2] + 1};
                    qu.add(temp1);
                }
            }
        }
        return -1;
    }
}
