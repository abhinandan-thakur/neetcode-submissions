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
    TreeNode *p, *q;
    TreeNode* lca(TreeNode *node) {
        if (!node) return nullptr;
        if (node == p || node == q) return node;
        TreeNode *left = lca(node->left);
        TreeNode *right = lca(node->right);
        if (left && right) return node;
        else if (!left && !right) return nullptr;
        else if (!left) return right;
        return left;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // DO THIS AGAIN
        this->p = p;
        this->q = q;
        return lca(root);
    }
};
