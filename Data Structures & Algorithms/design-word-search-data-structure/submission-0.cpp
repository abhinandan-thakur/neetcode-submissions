class TrieNode {
    public:
    TrieNode* children[26];
    bool end;
    TrieNode() {
        for(int i = 0; i < 26; i++) this->children[i] = nullptr;                    
        end = false;
    }
};
TrieNode *root;
class WordDictionary {
private:
    bool dfs(TrieNode *node, string &word, int index = 0) {
        if(index == word.size()) return node->end;
        if(word[index] == '.') {
            for(int j = 0; j < 26; j++) {
                if(node->children[j] == nullptr) continue;
                if(dfs(node->children[j], word, index+1)) return true;
            }
            return false;
        }
        int ind = word[index]-'a';
        if(node->children[ind] == nullptr) return false;
        return dfs(node->children[ind], word, index+1);
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return dfs(node,word,0);
    }
};
