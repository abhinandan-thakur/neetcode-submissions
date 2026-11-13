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
    TreeNode* cook(stringstream &s) {
        string tok;
        getline(s, tok, ',');
        if(tok.empty() || tok == "N") return nullptr;
        TreeNode *curr = new TreeNode(stoi(tok));
        curr->left = cook(s);
        curr->right = cook(s);
        return curr;
    }

    void bake(TreeNode *curr, string &s) {
        if(!curr) {
            s += "N,";
            return;
        }
        s += to_string(curr->val)+',';
        bake(curr->left, s);
        bake(curr->right, s);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string path = "";
        bake(root, path);
        return path;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream t(data);
        return cook(t);
    }
};
