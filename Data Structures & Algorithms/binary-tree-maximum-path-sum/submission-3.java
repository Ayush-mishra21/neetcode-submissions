/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    int ans = Integer.MIN_VALUE;
    int solve(TreeNode root) {
        if (root == null)
            return 0;
        int left = solve(root.left);
        int right = solve(root.right);
        ans = Math.max(ans,
            Math.max(
                left + right + root.val, Math.max(left + root.val, Math.max(right + root.val, root.val))));
        return Math.max(left + root.val, Math.max(right + root.val, root.val));
    }
    public int maxPathSum(TreeNode root) {
        solve(root);
        return ans;
    }
}
