/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int solve(TreeNode* root, int max_) {
        if (root == NULL) return 0;
        int ans = 0;
        if (root->val >= max_) {
            ans++;
        }
        int left = solve(root->left, max(max_, root->val));
        int right = solve(root->right, max(max_, root->val));
        return left + right + ans;
    }
    int goodNodes(TreeNode* root) { return solve(root, -102); }
};
