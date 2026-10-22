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
    bool solve(TreeNode *root, int max_, int min_){
        if(root == NULL)return true;
        if(root->val >= max_ || root->val <= min_)return false;
        return solve(root->left, min(root->val, max_), min_) && solve(root->right, max_ , max(min_, root->val));
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MAX, INT_MIN);
    }
};
