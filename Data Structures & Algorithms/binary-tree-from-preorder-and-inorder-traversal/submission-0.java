class Solution {
    int ind = 0;

    TreeNode contruct(int[] preorder, int[] inorder, int i, int j) {
        if (i > j || ind >= preorder.length)
            return null;

        int target = preorder[ind++];
        int find_ind = i;

        while (find_ind <= j && inorder[find_ind] != target) {
            find_ind++;
        }

        TreeNode node = new TreeNode(target);

        node.left = contruct(preorder, inorder, i, find_ind - 1);
        node.right = contruct(preorder, inorder, find_ind + 1, j);

        return node;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        ind = 0;
        return contruct(preorder, inorder, 0, inorder.length - 1);
    }
}
