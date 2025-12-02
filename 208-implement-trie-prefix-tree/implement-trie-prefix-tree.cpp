class Trie {
    Trie* children[26] = {};
    bool isEnd = false;
public:
    Trie() {}
    
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};