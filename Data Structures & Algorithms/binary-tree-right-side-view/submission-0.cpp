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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> qu;
        if (root == NULL) return ans;
        qu.push(root);
        while (!qu.empty()) {
            int n = qu.size();
            vector<int> res;
            for (int i = 0; i < n; i++) {
                if (i == n - 1) ans.push_back(qu.front()->val);
                if (qu.front()->left) {
                    qu.push(qu.front()->left);
                }
                if (qu.front()->right) {
                    qu.push(qu.front()->right);
                }
                qu.pop();
            }
        }
        return ans;
    }
};
