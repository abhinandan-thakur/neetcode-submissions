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
    int dfs(TreeNode *node, int maxima = INT_MIN) {
        if(!node) return 0;
        int good = 0;
        if(node->val >= maxima) good++;
        maxima = max(maxima, node->val);
        int left = dfs(node->left, maxima);
        int right = dfs(node->right, maxima);
        return left+right+good;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root);
    }
};
