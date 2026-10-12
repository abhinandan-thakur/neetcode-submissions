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
    TreeNode *p;
    TreeNode *q;
    TreeNode *found = nullptr;
    TreeNode *dfs(TreeNode *root) {
        if(!root) return nullptr;
        else if(root == p || root == q) return root;
        TreeNode *left = dfs(root->left);
        TreeNode *right = dfs(root->right);
        if ( (left == p && right == q) || (left == q && right == p) ) found = root;
        else if ((left == p) || left == q) return left;
        else if ((right == p) || (right == q)) return right;
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        TreeNode *ans2 = dfs(root);
        if(!found) return ans2;
        return found;
    }
};
