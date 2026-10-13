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
#include <climits>
class Solution {
private:
    bool dfs(TreeNode *node, int low = INT_MIN, int high = INT_MAX) {
        if(!node) return true;
        if (node->val <= low || node->val >= high) return false;
        bool left = dfs(node->left, low, node->val);
        bool right = dfs(node->right, node->val, high);
        return left&&right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};
