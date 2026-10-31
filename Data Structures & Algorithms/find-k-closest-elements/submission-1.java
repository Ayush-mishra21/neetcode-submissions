class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> ans = new ArrayList<>();
        List<int[]> res = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            int diff = Math.abs(x - arr[i]);
            int temp[] = {diff, arr[i]};
            res.add(temp);
        }
        Collections.sort(res, (int[] a, int[] b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });
        for (int i = 0; i < k; i++) {
            ans.add(res.get(i)[1]);
        }
        Collections.sort(ans);
        return ans;
    }
}