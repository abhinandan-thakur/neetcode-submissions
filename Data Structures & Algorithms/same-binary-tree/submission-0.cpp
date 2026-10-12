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
    bool dfs(TreeNode *p, TreeNode *q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;
        if((p->val == q->val)) {
            bool left = dfs(p->left, q->left);
            bool right = dfs(p->right, q->right);
            return (left&&right);
        }
        return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};
