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
    int answer = INT_MIN;
    int pathSum(TreeNode *node) {
        if(!node) return 0;
        int left = max(pathSum(node->left),0);
        int right = max(pathSum(node->right),0);
        answer = max(answer, node->val + left + right);
        return max(left, right) + node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return answer;
    }
};
