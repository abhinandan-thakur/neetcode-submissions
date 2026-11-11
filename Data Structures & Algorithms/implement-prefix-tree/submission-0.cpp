class TrieNode {
    public:
        TrieNode* children[26];
        bool end;
        TrieNode() {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
            end = false;
        }
};
TrieNode *root;
class PrefixTree {
private:

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i]-'a';
            if(node->children[index] == nullptr) node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i]-'a';
            if(node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        if(node->end) return true;
        return false;
    }
    
    bool startsWith(string word) {
        TrieNode *node = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i]-'a';
            if(node->children[index] == nullptr) return false;
            node = node->children[index];
        }
        return true;
    }
};
