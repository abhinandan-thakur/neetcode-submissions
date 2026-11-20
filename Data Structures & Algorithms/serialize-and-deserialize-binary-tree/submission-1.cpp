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

class Codec {
private:
    void dfs(TreeNode *root, string &ans) {
        if(root == nullptr) {
            ans += "N,";
            return;
        }
        ans += to_string(root->val) + ",";
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    TreeNode* build(stringstream &ss) {
        string data;
        getline(ss, data, ',');
        if(data == "N") return nullptr;
        TreeNode *root = new TreeNode(stoi(data));
        root->left = build(ss);
        root->right = build(ss);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};
