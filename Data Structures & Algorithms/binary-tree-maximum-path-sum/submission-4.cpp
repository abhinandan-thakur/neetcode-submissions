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
private:
    int ans = INT_MIN;
    int dfs(TreeNode *curr) {
        if(!curr) return 0;
        int left = max(dfs(curr->left), 0);
        int right = max(dfs(curr->right), 0);
        ans = max(ans, left+right+curr->val);
        return curr->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
