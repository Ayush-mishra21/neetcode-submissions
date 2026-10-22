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
    priority_queue<int> maxpq;
    void solve(TreeNode* root, int k) {
        if (root == NULL) return;
        maxpq.push(root->val);
        if (maxpq.size() > k) 
            maxpq.pop();
        solve(root->left, k);
        solve(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) 
            return -1;
        solve(root, k);
        // int n = maxpq.size() - 1;
        // while (n--) {
        //     maxpq.pop();
        // }
        return maxpq.top();
    }
};
