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
    boolean solve(TreeNode root, int max_, int min_){
        if(root == null)return true;
        if(root.val >= max_ || root.val <= min_)return false;
        return solve(root.left, Math.min(root.val, max_), min_) && solve(root.right, max_ , Math.max(min_, root.val));
    }
    public boolean isValidBST(TreeNode root) {
        return solve(root, Integer.MAX_VALUE, Integer.MIN_VALUE);
    }
}
