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
    bool found = false;
    bool matcher(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;
        if(p->val == q->val) {
            bool left = matcher(p->left, q->left);
            bool right = matcher(p->right, q->right);
            return left&&right;
        }
        return false;
    }

    bool search(TreeNode *p, TreeNode *q) {
        if(found) return true;
        if(!p) return false;
        if(p->val == q->val) found = found || matcher(p,q);
        bool left = search(p->left, q);
        bool right = search(p->right, q);
        return left||right;
        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        search(root, subRoot);
        return found;
    }
};
