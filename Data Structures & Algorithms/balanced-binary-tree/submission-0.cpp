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
    unordered_map<TreeNode*, int> mp;
    int solve(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        return mp[root] = left > right?left + 1:right + 1;
    }
    bool Balanced(TreeNode* root) {
        if (root == NULL) return true;
        if (root->left && root->right) {
            if (abs(mp[root->left] - mp[root->right]) > 1) return false;
        } else if (root->left) {
            if (mp[root->left] > 1) return false;
        } else if (root->right) {
            if (mp[root->right] > 1) return false;
        }
        return Balanced(root->left) && Balanced(root->right);
    }
    bool isBalanced(TreeNode* root) {
       solve(root);
       return Balanced(root);
    }
};
