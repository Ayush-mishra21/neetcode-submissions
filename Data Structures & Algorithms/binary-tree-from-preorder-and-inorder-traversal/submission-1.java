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
    int ind = 0;
    TreeNode contruct(int[] preorder, int[] inorder, int i, int j) {
        if (ind >= preorder.length || i < 0 || i <= j)
            return null;
        int target = preorder[ind++];
        int find_ind = i;

        while (find_ind <= j && inorder[find_ind] != target) {
            find_ind++;
        }
        TreeNode node = new TreeNode(inorder[find_ind]);
        node.left = contruct(preorder, inorder, i, find_ind - 1);
        node.right = contruct(preorder, inorder, find_ind + 1, j);
        return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return contruct(preorder, inorder, 0, preorder.length - 1);
    }
}
