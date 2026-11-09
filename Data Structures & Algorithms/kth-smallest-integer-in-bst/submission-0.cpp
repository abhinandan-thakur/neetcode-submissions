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
    // normal inorder traversal
    int ans = -1;
    void recursion(TreeNode* node, int &k) {
        if(!node) return;
        recursion(node->left, k);
        if(k == 1) ans = node->val;
        k = k-1;
        recursion(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        recursion(root, k);
        return ans;
    }
};
